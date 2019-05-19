#include "TranslatorFromXml.h"


TranslatorFromXml::TranslatorFromXml(Queue* queryQueue, Queue* resultingQueryQueue, Queue* requestQueue, ErrorQueue* errorQueue)
	:	running(false),
		dataBaseMap(),
		queueItem(),
		request(),
		document(),
		queryQueuePtr(queryQueue),
		resultingQueryQueuePtr(resultingQueryQueue),
		requestQueuePtr(requestQueue),
		errorQueuePtr(errorQueue)
{	}


TranslatorFromXml::~TranslatorFromXml()
{	
	stop();
}

void TranslatorFromXml::start()
{
	running = true;
	TRANSLATOR_XML_THREAD = std::thread(&TranslatorFromXml::run, this);
}

void TranslatorFromXml::stop()
{
	if (TRANSLATOR_XML_THREAD.joinable())
	{
		TRANSLATOR_XML_THREAD.join();
		running = false;
	}
}

void TranslatorFromXml::run()
{
	while (running)
	{
		if (loadDocument()) 
			translateDocument();
	}
}

void TranslatorFromXml::translateDocument()
{	
	try
	{
		setRequestId();
		setTable();
		setMethod();
		prepareQuery();

		if (methodPointer->isResulting())
		{
			resultingQueryQueuePtr->addItem(std::move(queueItem));
		}
		else
		{
			queryQueuePtr->addItem(std::move(queueItem));
		}
	}
	catch (ExceptionInterface& exception)
	{
		errorQueuePtr->addItem(std::move(queueItem), exception);
	}
	
}

void TranslatorFromXml::setRequestId()
{
	int id = document->getRequestID();
	queueItem->setId(id);
}

void TranslatorFromXml::setTable()
{
	string tableName = document->findTableName();			// WARNING!!! throws exception	
	tablePointer = &dataBaseMap.findTable(tableName);		// WARNING!!! throws exception
}

void TranslatorFromXml::setMethod()
{	
	string methodName = document->findMethodName();			// WARNING!!! throws exception
	MethodsMapper* methodsMapper = tablePointer->getMethodsMapper();
	methodPointer = &methodsMapper->findMethod(methodName);	// WARNING!!! throws exception
}


void TranslatorFromXml::prepareQuery()
{
	unique_ptr<ContentInterface> queryPtr = methodPointer->generateQuery(*document);	// WARNING!!! throws exception

	queueItem->changeContent(queryPtr);
}

bool TranslatorFromXml::loadDocument()
{
	if (requestQueuePtr->isEmpty())
		return false;

	queueItem = std::move(requestQueuePtr->getItem());

	return initializeFields();
}

bool TranslatorFromXml::initializeFields()
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
