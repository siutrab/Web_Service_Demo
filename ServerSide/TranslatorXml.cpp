#include "TranslatorXml.h"


	RequestQueue* TranslatorXml::requestQueuePtr;
	QueryQueue* TranslatorXml::queryQueuePtr;
	ErrorQueue* TranslatorXml::errorQueuePtr;

	void TranslatorXml::setRequestQueuePtr(RequestQueue* pointer)
	{
		TranslatorXml::requestQueuePtr = pointer; // Settet in RequestsQueue object
		const_cast<const RequestQueue*>(TranslatorXml::requestQueuePtr);
	}

	void TranslatorXml::setQueryQueuePtr(QueryQueue* pointer)
	{
		TranslatorXml::queryQueuePtr = pointer; // Settet in QueryQueue object
		const_cast<const QueryQueue*>(TranslatorXml::queryQueuePtr);
	}

	void TranslatorXml::setErrorQueuePtr(ErrorQueue* const pointer)
	{
		TranslatorXml::errorQueuePtr = pointer; // Settet in ErrorQueue object
		const_cast<const ErrorQueue*>(TranslatorXml::errorQueuePtr);
	}


TranslatorXml::TranslatorXml()
	:	running(false),
		documentIsLoaded(false),
		methodsMapper(),
		dataBaseMap()
{	}


TranslatorXml::~TranslatorXml()
{	}

void TranslatorXml::start()
{
	TRANSLATOR_XML_THREAD = std::thread(&TranslatorXml::run, this);
}

void TranslatorXml::stop()
{
	TRANSLATOR_XML_THREAD.join();
	running = false;
}

void TranslatorXml::run()
{
	running = true;
	while (running)
	{
		releaseFields();
		if(loadDocument())
			translateDocument();
	}
}

bool TranslatorXml::translateDocument()
{	
	findTable();
	findMethod();
	return false;
}

bool TranslatorXml::loadDocument()
{
	if (requestQueuePtr->isEmpty())
		return false;

	queueItem = unique_ptr<QueueItem>(requestQueuePtr->getItem());

	initializeFields();
	return true;
}

void TranslatorXml::initializeFields()
{
	ContentInterface& contentInterface = *queueItem->getContent();
	request = static_cast<Request*>(&contentInterface);

	document.reset(new DocumentXml(*request));
	documentIsLoaded = true;
}

void TranslatorXml::releaseFields()
{
	queueItem->changeContent(*query);
	QueueItem* queueItemObject = queueItem.release();
	queryQueuePtr->addItem(*queueItem);
}

void TranslatorXml::findTable()
{
	// Example
	// <table name = "materials">	... node "table", attribute "name", attribute.value "materials"
	
	string nodeName("table");
	string attribute("name");
	
	try
	{
		unique_ptr<string> tableName = document->getNodeAttriute(nodeName, attribute);	// WARNING!!! throws exception	
		tablePointer = dataBaseMap.findTable(*tableName);								// WARNING!!! throws exception
	}
	catch(ExceptionInterface& exception)
	{
		auto queueItemPtr = queueItem.release();
		errorQueuePtr->addItem(*queueItemPtr, exception);
	}
}

void TranslatorXml::findMethod()
{
	string nodeName("method");
	string attribute("name");

	try
	{
		unique_ptr<string> methodName = document->getNodeAttriute(nodeName, attribute);	// WARNING!!! throws exception
		methodPointer = methodsMapper.findMethod(*methodName);							// WARNING!!! throws exception
	}
	catch (ExceptionInterface& exception)
	{
		document->recognizeInvalid();
		auto queueItemPtr = queueItem.release();
		errorQueuePtr->addItem(*queueItemPtr, exception);
	}
}
