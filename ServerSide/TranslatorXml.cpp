#include "MethodsMapper.h"
#include "TranslatorXml.h"

	RequestQueue* TranslatorXml::requestQueuePtr;

	void TranslatorXml::setRequestQueuePtr(RequestQueue* pointer)
	{
		TranslatorXml::requestQueuePtr = pointer; // Settet in RequestsQueue object
		const_cast<const RequestQueue*>(TranslatorXml::requestQueuePtr);
	}


TranslatorXml::TranslatorXml()
	: running(false),
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
		loadDocument();
		translateDocument();
	}
}

bool TranslatorXml::translateDocument()
{

	
	findTable();
	findMethod();
	return false;
}

void TranslatorXml::loadDocument()
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