#include "RequestTranslatorXml.h"


RequestTranslatorXml::RequestTranslatorXml(Queue* queryQueue, Queue* resultingQueryQueue, Queue* requestQueue, ErrorHandler* errorQueue, DataBaseMap* databaseMap)
	:	running(false),
		dataBaseMap(databaseMap),
		queueItem(),
		request(),
		document(),
		queryQueuePtr(queryQueue),
		resultingQueryQueuePtr(resultingQueryQueue),
		requestQueuePtr(requestQueue),
		errorHandlerPtr(errorQueue)
{	}


RequestTranslatorXml::~RequestTranslatorXml()
{	}


void RequestTranslatorXml::start()
{
	running = true;
	TRANSLATOR_XML_THREAD = std::thread(&RequestTranslatorXml::run, this);
}


void RequestTranslatorXml::stop()
{
	running = false;
	if (TRANSLATOR_XML_THREAD.joinable())
		TRANSLATOR_XML_THREAD.join();
}


void RequestTranslatorXml::run()
{
	while (running)
	{
		if (loadDocument()) 
			translateDocument();
	}
}


void RequestTranslatorXml::translateDocument()
{	
	try
	{
		if (document->isDisconnectRequest())
			disconnectClient();
		else
		{
			setRequestId();
			setTable();
			setMethod();
			prepareQuery();

			if (methodPointer->isResulting())
				resultingQueryQueuePtr->addItem(std::move(queueItem));
			else
				queryQueuePtr->addItem(std::move(queueItem));
		}
		
	}
	catch (ExceptionInterface& exception)
	{
		errorHandlerPtr->createError(std::move(queueItem), exception);
	}
	
}

void RequestTranslatorXml::disconnectClient()
{
	Client* client = queueItem->getClientPointer();
	client->setDisconnected();
	queueItem->~QueueItem();
}

void RequestTranslatorXml::setRequestId()
{
	int id = document->getRequestID();
	queueItem->setId(id);
}

void RequestTranslatorXml::setTable()
{
	string tableName = document->findTableName();			// WARNING!!! throws exception	
	tablePointer = &dataBaseMap->findTable(tableName);		// WARNING!!! throws exception
}

void RequestTranslatorXml::setMethod()
{	
	string methodName = document->findMethodName();			// WARNING!!! throws exception
	MethodsCollection* methodsMapper = tablePointer->getMethodsMapper();
	methodPointer = &methodsMapper->findMethod(methodName);	// WARNING!!! throws exception
}


void RequestTranslatorXml::prepareQuery()
{
	unique_ptr<ContentInterface> queryPtr = methodPointer->generateQuery(*document);	// WARNING!!! throws exception

	queueItem->changeContent(queryPtr);
}

bool RequestTranslatorXml::loadDocument()
{
	if (requestQueuePtr->isEmpty())
		return false;

	queueItem = std::move(requestQueuePtr->getItem());

	return initializeFields();
}

bool RequestTranslatorXml::initializeFields()
{
	try
	{
		unique_ptr<ContentInterface> contentInterface(std::move(queueItem->getContentObject()));
	
		request = unique_ptr<Request>(static_cast<Request*>(contentInterface.release()));
		document.reset(new DocumentXml(*request));
		return true;
	}
	catch(...)
	{
		return false;
	}
}
