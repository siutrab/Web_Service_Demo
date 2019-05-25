#pragma once
#include "MethodInterface.h"
#include "DataBaseMap.h"
#include "MethodsCollection.h"
#include "QueryQueue.h"
#include "QueueItem.h"
#include "ErrorQueue.h"
#include <thread>

class Request;
class DataBaseMap;
class MethodInterface;
class TableInterface;
class MethodsCollection;
class ErrorQueue;

class RequestTranslatorXml
{
	std::thread TRANSLATOR_XML_THREAD;
	bool running;


	Queue* requestQueuePtr;
	Queue* queryQueuePtr;
	Queue* resultingQueryQueuePtr;

	ErrorQueue* errorQueuePtr;

	DataBaseMap* dataBaseMap;


		unique_ptr<QueueItem> queueItem;
		unique_ptr<Request> request;

		unique_ptr<DocumentXml> document;

		TableInterface* tablePointer;
		MethodInterface* methodPointer;
		
		
	void run();
	bool loadDocument();
	bool initializeFields();
	void translateDocument();
	void prepareQuery();

	void setRequestId();
	void setTable();
	void setMethod();
	
public:
	RequestTranslatorXml(Queue* queryQueue, Queue* resultingQueryQueue, Queue* requestQueue, ErrorQueue* errorQueue, DataBaseMap* databaseMap);
	~RequestTranslatorXml();
	void start();
	void stop();

};

