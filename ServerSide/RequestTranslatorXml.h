#pragma once
#include "MethodInterface.h"
#include "DataBaseMap.h"
#include "MethodsCollection.h"
#include "QueryQueue.h"
#include "QueueItem.h"
#include "ErrorHandler.h"
#include <thread>

class Request;
class DataBaseMap;
class MethodInterface;
class TableInterface;
class MethodsCollection;
class ErrorHandler;

class RequestTranslatorXml
{
	std::thread TRANSLATOR_XML_THREAD;
	bool running;


	Queue* requestQueuePtr;
	Queue* queryQueuePtr;
	Queue* resultingQueryQueuePtr;

	ErrorHandler* errorHandlerPtr;

	DataBaseMap* dataBaseMap;


		unique_ptr<QueueItem> queueItem;
		unique_ptr<Request> request;

		unique_ptr<DocumentXml> document;

		TableInterface* tablePointer;
		MethodInterface* methodPointer;
		
		
	void run();					// main loop of thread
	bool loadDocument();
	bool initializeFields();	// Sets queueItem and request objects. Returns true whe uv
	void translateDocument();	// Coordinates the translation procedure
	void prepareQuery();		// Generte proper SQL statement
	void disconnectClient();	// Sets the client disconnected and deletes request

	void setRequestId();		// Sets id to QueueUtmem fe
	void setTable();			// Sets specific table from database
	void setMethod();			// Sets method from table
	
public:
	RequestTranslatorXml(Queue* queryQueue, Queue* resultingQueryQueue, Queue* requestQueue, ErrorHandler* errorQueue, DataBaseMap* databaseMap);
	~RequestTranslatorXml();
	void start();				// starts thread
	void stop();				// joins thread

};

