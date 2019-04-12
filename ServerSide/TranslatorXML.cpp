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
	loadDocument();
}
void TranslatorXML::translateResponse()
{

}

LoadedDocument* TranslatorXML::loadDocument()
{

		Request* request = requestsQueue->getRequest();
		if (request != nullptr)
		{
			std::string* requestString = request->getRequest();
			LoadedDocument* loadedDocument = new LoadedDocument();
			loadedDocument->document.load_buffer_inplace_own(requestString, requestString->size());
			return loadedDocument;	
		}
		else return nullptr;
}
