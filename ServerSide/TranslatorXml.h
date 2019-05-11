#pragma once

#include "MethodInterface.h"
#include "DataBaseMap.h"
#include "MethodsMapper.h"
#include "QueryQueue.h"
#include "QueueItem.h"
#include "ErrorQueue.h"
#include <thread>

class Request;
class RequestQueue;
class DataBaseMap;
class MethodInterface;
class TableInterface;
class MethodsMapper;
class QueryQueue;
class ErrorQueue;

class TranslatorXml
{
	std::thread TRANSLATOR_XML_THREAD;
	bool running;


	static RequestQueue* requestQueuePtr;
	static QueryQueue* queryQueuePtr;
	static ErrorQueue* errorQueuePtr;

	DataBaseMap dataBaseMap;
	MethodsMapper methodsMapper;

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

	void setTable();
	void setMethod();

public:
	TranslatorXml();
	~TranslatorXml();
	void start();
	void stop();

	static void setRequestQueuePtr(RequestQueue* const pointer);
	static void setQueryQueuePtr(QueryQueue* const pointer);
	static void setErrorQueuePtr(ErrorQueue* const pointer);

};

