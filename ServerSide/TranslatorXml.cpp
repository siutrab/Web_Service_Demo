#include "TranslatorXml.h"


TranslatorXml::TranslatorXml(Queue* queryQueue, Queue* requestQueue, ErrorQueue* errorQueue)
	:	running(false),
		methodsMapper(),
		dataBaseMap(),
		queueItem(),
		request(),
		document(),
		queryQueuePtr(queryQueue),
		requestQueuePtr(requestQueue),
		errorQueuePtr(errorQueue)
{	}


TranslatorXml::~TranslatorXml()
{	}

void TranslatorXml::start()
{
	running = true;
	TRANSLATOR_XML_THREAD = std::thread(&TranslatorXml::run, this);
}

void TranslatorXml::stop()
{
	TRANSLATOR_XML_THREAD.join();
	running = false;
}

void TranslatorXml::run()
{
	while (running)
	{
		if (loadDocument()) 
			translateDocument();
	}
}

void TranslatorXml::translateDocument()
{	
	try
	{
		setRequestId();
		setTable();
		setMethod();
		prepareQuery();
		
		queryQueuePtr->addItem(std::move(queueItem));
	}
	catch (ExceptionInterface& exception)
	{
		errorQueuePtr->addItem(std::move(queueItem), exception);
	}
	
}

void TranslatorXml::setRequestId()
{
	int id = document->getRequestID();
	queueItem->setId(id);
}

void TranslatorXml::setTable()
{
	string tableName = document->findTableName();			// WARNING!!! throws exception	
	tablePointer = &dataBaseMap.findTable(tableName);		// WARNING!!! throws exception
}

void TranslatorXml::setMethod()
{	
	string methodName = document->findMethodName();			// WARNING!!! throws exception
	methodPointer = &methodsMapper.findMethod(methodName);	// WARNING!!! throws exception
}


void TranslatorXml::prepareQuery()
{
	unique_ptr<ContentInterface> queryPtr = methodPointer->generateQuery(*document);	// WARNING!!! throws exception

	queueItem->changeContent(queryPtr);
}

bool TranslatorXml::loadDocument()
{
	if (requestQueuePtr->isEmpty())
		return false;

	queueItem = std::move(requestQueuePtr->getItem());

	return initializeFields();
}

bool TranslatorXml::initializeFields()
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
