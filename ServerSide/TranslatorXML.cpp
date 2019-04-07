#include "pch.h"
#include "TranslatorXML.h"


TranslatorXML::TranslatorXML()
	:	requestsQueue(RequestsQueue::getRequestsQueuePtr())
{
}


TranslatorXML::~TranslatorXML()
{
}

void TranslatorXML::translateRequest()
{
	//RequestResponseObject* reqResObj = requestsQueue->getConversation();
	//std::string* request = reqResObj->getRequest();
	//pugi::xml_parse_result result = pugi::xml_document::load_string(request);
}
void TranslatorXML::translateResponse()
{

}