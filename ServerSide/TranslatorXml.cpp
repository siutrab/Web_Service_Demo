#include "TranslatorXml.h"

	RequestQueue* TranslatorXml::requestQueuePtr;

	void TranslatorXml::setRequestQueuePtr(RequestQueue* pointer)
	{
		TranslatorXml::requestQueuePtr = pointer; // Settet in RequestsQueue object
		const_cast<const RequestQueue*>(TranslatorXml::requestQueuePtr);
	}

	QueryQueue* TranslatorXml::queryQueuePtr;

	void TranslatorXml::setQueryQueuePtr(QueryQueue* pointer)
	{
		TranslatorXml::queryQueuePtr = pointer; // Settet in RequestsQueue object
		const_cast<const QueryQueue*>(TranslatorXml::queryQueuePtr);
	}


TranslatorXml::TranslatorXml()
	:	running(false),
		documentIsLoaded(false),
		methodsMapper(),
		dataBaseMap()
{
}


TranslatorXml::~TranslatorXml()
{
}

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
		popCurrentDocument();
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

	request = requestQueuePtr->getItem();
	document = shared_ptr<DocumentXml>(new DocumentXml(*request));	//!!!
	documentIsLoaded = true;
	return true;
	
}

void TranslatorXml::popCurrentDocument()
{

}

void TranslatorXml::findTable()
{
	// Example
	// <table name = "materials">	... node "table", attribute "name", attribute.value "materials"
	
	string nodeName = "table";
	string attribute = "name";
	
	try
	{
		unique_ptr<string> tableName = document->getNodeAttriute(nodeName, attribute);	// WARNING!!! throws exception	
		tablePointer = dataBaseMap.findTable(*tableName);								// WARNING!!! throws exception
	}
	catch(ExceptionInterface& exceptionReference)
	{
		document->addException(exceptionReference);
		document->recognizeInvalid();
	}
}

void TranslatorXml::findMethod()
{
	string nodeName = "method";
	string attribute = "name";

	try
	{
		unique_ptr<string> methodName = document->getNodeAttriute(nodeName, attribute);	// WARNING!!! throws exception
		methodPointer = methodsMapper.findMethod(*methodName);							// WARNING!!! throws exception
	}
	catch (ExceptionInterface& exceptionReference)
	{
		document->addException(exceptionReference);
		document->recognizeInvalid();
	}
}