#pragma once

#include "MethodInterface.h"
#include "DataBaseMap.h"
#include "MethodsMapper.h"
#include "QueryQueue.h"
#include <thread>

class Request;
class RequestQueue;
class DataBaseMap;
class MethodInterface;
class TableInterface;
class MethodsMapper;
class QueryQueue;

class TranslatorXml
{
	std::thread TRANSLATOR_XML_THREAD;
	bool running;


	static RequestQueue* requestQueuePtr;
	static QueryQueue* queryQueuePtr;

	DataBaseMap dataBaseMap;
	MethodsMapper methodsMapper;
		shared_ptr<DocumentXml> document;
		bool documentIsLoaded;
		shared_ptr<Request> request;
		shared_ptr<TableInterface> tablePointer;
		shared_ptr<MethodInterface> methodPointer;

		

	void run();
	bool loadDocument();
	void popCurrentDocument();
	bool translateDocument();

	void findTable();
	void findMethod();
	bool findParameters();

public:
	TranslatorXml();
	~TranslatorXml();
	void start();
	void stop();

	static void setRequestQueuePtr(RequestQueue* const pointer);
	static void setQueryQueuePtr(QueryQueue* const pointer);

};

