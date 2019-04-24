#include "pch.h"
#include "ExceptionsSystem.h"
#include "RequestHandler.h"

RequestsQueue* RequestHandler::requestsQueue;
void RequestHandler::setRequestQueuePointer(RequestsQueue* pointer)
{
	requestsQueue = pointer;
	const_cast<RequestsQueue* const>(requestsQueue);
}

RequestHandler::RequestHandler()
	:	dataBaseMap(new DataBaseMap()),
		//document(new DocumentXml()),
		running(false)
{	
	REQUEST_HANDLER_THREAD = thread(&RequestHandler::start, this);
}


RequestHandler::~RequestHandler()
{
}

void RequestHandler::translateRequest()
{
	//unique_ptr<LoadedXmlDocument> document = loadXmlDocument();		// << --- loadXmlDocument method needs REFACTOR!!!
	if (document->isLoadedSuccesfully())
	{
		//pugi::xml_node tableNode = document->document.document_element();
		//pugi::xml_attribute attribute;
		//attribute = tableNode.first_attribute();

		dataBaseMap->assignTableMap(*document);
		if (document->tableIsAssigned())
		{

		}
		//try
		//{
		//	pugi::xml_node tableNode = document->document.child("table");
		//	string tableName = tableNode.attribute("name").value();

		//	TableInterface* tableMap = dataBaseMap->findTable(tableName);	// WARNING!!! throws exception
		//}
		//catch(ExceptionInterface)
		//{

		//}

		
		//std::cout << "\nname: " << blahNode.name() << std::endl << "value: "<< blahNode.first_child().child_value() << std::endl;
	}
}



void RequestHandler::translateResponse()
{

}

void RequestHandler::start()
{
	running = true;
	while (running)
	{
		
	}
}

void RequestHandler::stop()
{
	running = false;
}

//	I REALLY NEED REFACTOR!!!!
//unique_ptr<LoadedXmlDocument> RequestHandler::loadXmlDocument()
//{
//	unique_ptr<LoadedXmlDocument> loadedDocument(new LoadedXmlDocument());
//	
//	if (requestsQueue->isEmpty())
//		loadedDocument->loadedSuccesfully = false;
//	else 
//	{
//		Request& request = requestsQueue->getItem();
//		string* requestString = request->getContent();
//		const char* charString = requestString->c_str();
//		loadedDocument->document.load_string(charString);
//		loadedDocument->loadedSuccesfully = true;
//	}
//	return loadedDocument;	
//}
