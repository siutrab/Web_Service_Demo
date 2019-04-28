#pragma once

#include "MethodInterface.h"
#include "DataBaseMap.h"
#include "MethodsMapper.h"
#include <thread>

class RequestQueue;
class DataBaseMap;
class MethodInterface;
class TableInterface;
class MethodsMapper;

class TranslatorXml
{
	std::thread TRANSLATOR_XML_THREAD;
	bool running;


	static RequestQueue* requestQueuePtr;

	DataBaseMap dataBaseMap;
	MethodsMapper methodsMapper;
		shared_ptr<DocumentXml> document;
		shared_ptr<TableInterface> tablePointer;
		shared_ptr<MethodInterface> methodPointer;

		

	void run();
	void loadDocument();
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

};

