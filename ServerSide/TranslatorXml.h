#pragma once

#include "MethodInterface.h"
#include "DataBaseMap.h"
#include "MethodsMapper.h"
#include "NoResultQueryQueue.h"
#include "ResultQueryQueue.h"
#include "QueueItem.h"
#include "ErrorQueue.h"
#include <thread>

class Request;
class RequestQueue;
class DataBaseMap;
class MethodInterface;
class TableInterface;
class MethodsMapper;
class NoResultQueryQueue;
class ErrorQueue;

class TranslatorXml
{
	std::thread TRANSLATOR_XML_THREAD;
	bool running;


	static RequestQueue* requestQueuePtr;
	static NoResultQueryQueue* noResultQueryQueuePtr;
	static ResultQueryQueue* resultQueryQueuePtr;
	static ErrorQueue* errorQueuePtr;

	DataBaseMap dataBaseMap;
	MethodsMapper methodsMapper;

		unique_ptr<QueueItem> queueItem;
		unique_ptr<Request> request;

		unique_ptr<DocumentXml> document;

		TableInterface* tablePointer;
		MethodInterface* methodPointer;
		Queue* queryQueuePointer;

		
	void run();
	bool loadDocument();
	bool initializeFields();
	void translateDocument();
	void prepareQuery();

	void setTable();
	void setMethod();
	void chooseQueryQueue();
public:
	TranslatorXml();
	~TranslatorXml();
	void start();
	void stop();

	static void setRequestQueuePtr(RequestQueue* const pointer);
	static void setNoResultQueryQueuePtr(NoResultQueryQueue* const pointer);
	static void setResultQueryQueuePtr(ResultQueryQueue* const pointer);
	static void setErrorQueuePtr(ErrorQueue* const pointer);

};

