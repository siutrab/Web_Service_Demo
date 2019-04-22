#include "pch.h"
#include "TranslatorXML.h"

RequestsQueue* TranslatorXML::requestsQueue;
void TranslatorXML::setRequestQueuePointer(RequestsQueue* pointer)
{
	requestsQueue = pointer;
	const_cast<RequestsQueue* const>(requestsQueue);
}

TranslatorXML::TranslatorXML()

{
}


TranslatorXML::~TranslatorXML()
{
}

void TranslatorXML::translateRequest()
{
	LoadedDocument* document = loadDocument();
	if (document->loadedSuccesfully)
	{
		pugi::xml_node tableNode = document->document.document_element();
		pugi::xml_attribute attribute;

		attribute = tableNode.first_attribute();
		if (attribute.value() == "materials")
		{

		}
		std::cout << "\nname: " << blahNode.name() << std::endl << "value: "<< blahNode.first_child().child_value() << std::endl;
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
