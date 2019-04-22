#include "pch.h"
#include "TranslatorXML.h"

RequestsQueueXml* TranslatorXML::requestsQueue;
void TranslatorXML::setRequestQueuePointer(RequestsQueueXml* pointer)
{
	requestsQueue = pointer;
	const_cast<RequestsQueueXml* const>(requestsQueue);
}

TranslatorXML::TranslatorXML()

{
}


TranslatorXML::~TranslatorXML()
{
}

void TranslatorXML::translateRequest()
{
	LoadedDocument* document= loadDocument();
	if (document->loadedSuccesfully)
	{
	/*	pugi::xml_node blahNode = document->document.document_element();
		pugi::xml_attribute attribute;
		attribute = blahNode.first_attribute();
		std::cout << "name: " << blahNode.name() << std::endl << "value: "<< blahNode.first_child().child_value() << std::endl;*/
	}
	else delete document;
}
void TranslatorXML::translateResponse()
{

}


//	I REALLY NEED REFACTOR!!!!
LoadedDocument* TranslatorXML::loadDocument()
{

	LoadedDocument* loadedDocument = new LoadedDocument();
	
	if (requestsQueue->isEmpty())
		loadedDocument->loadedSuccesfully = false;
	else 
	{
		Request* request = requestsQueue->getItem();
		string* requestString = request->getRequest();
		const char* charString = requestString->c_str();
		loadedDocument->document.load_string(charString);
		loadedDocument->loadedSuccesfully = true;
	}
	return loadedDocument;	
}
