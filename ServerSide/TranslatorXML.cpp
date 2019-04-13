#include "pch.h"
#include "TranslatorXML.h"


TranslatorXML::TranslatorXML(RequestsQueue* pointer)
	:	requestsQueue(pointer)
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

LoadedDocument* TranslatorXML::loadDocument()
{

	Request* request = requestsQueue->getRequest();
	LoadedDocument* loadedDocument = new LoadedDocument();
	
	if (request != nullptr)
	{
		std::string* requestString = request->getRequest();
		const char* charString = requestString->c_str();
		loadedDocument->document.load_string(charString);
		//loadedDocument->document.load_buffer_inplace_own(requestString, requestString->size() / sizeof(std::string));
		loadedDocument->loadedSuccesfully = true;
	}
	else loadedDocument->loadedSuccesfully = false;
	return loadedDocument;	
}
