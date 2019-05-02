#pragma once

#include "MethodInterface.h"
#include "DataBaseMap.h"
#include "MethodsMapper.h"
#include "QueryQueue.h"
#include "QueueItem.h"
#include "ErrorQueue.h"
//#include "Request.h"
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
		Request* request;

		unique_ptr<DocumentXml> document;
		bool documentIsLoaded;

		unique_ptr<Query> query;

		shared_ptr<TableInterface> tablePointer;
		shared_ptr<MethodInterface> methodPointer;

		
	void run();
	void releaseFields();
	bool loadDocument();
	void initializeFields();
	bool translateDocument();

	void findTable();
	void findMethod();
	bool findParameters();

	void pushOnErrorQueue(ExceptionInterface& exception);
public:
	TranslatorXml();
	~TranslatorXml();
	void start();
	void stop();

	static void setRequestQueuePtr(RequestQueue* const pointer);
	static void setQueryQueuePtr(QueryQueue* const pointer);
	static void setErrorQueuePtr(ErrorQueue* const pointer);

};

