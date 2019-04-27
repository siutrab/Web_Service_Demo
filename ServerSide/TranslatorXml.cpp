#include "TranslatorXml.h"



TranslatorXml::TranslatorXml()
{
}


TranslatorXml::~TranslatorXml()
{
}

bool TranslatorXml::translateDocument()
{

	loadDocument();
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