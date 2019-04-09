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
	RequestResponseObject* reqResObj = requestsQueue->getRequest();
	std::string* requestString = reqResObj->getRequest();
	pugi::xml_document xmlDocument;
	xmlDocument.load_buffer_inplace_own(requestString, requestString->size());
}
void TranslatorXML::translateResponse()
{

}