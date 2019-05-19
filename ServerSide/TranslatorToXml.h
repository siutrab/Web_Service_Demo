#pragma once
#include "DocumentXml.h"
#include "ErrorQueue.h"
#include "MethodInterface.h"
#include "EntityInterface.h"
#include "Queue.h"
#include "jdbc/cppconn/resultset.h"
#include <thread>
#include <memory>

using std::unique_ptr;
using std::shared_ptr;
using std::thread;
using sql::ResultSet;

class TranslatorToXml
{
	bool running;

	thread TRANSLATOR_TO_XML_THREAD;
	ErrorQueue* errorQueue;
	Queue* responseQueue;
	Queue* entityQueue;

	unique_ptr<QueueItem> queueItem;
	unique_ptr<EntityCollection> content;
	ReadMethodInterface* method;
	shared_ptr<ResultSet> resultSet;

	unique_ptr<DocumentXml> document;
	
	void run();
	bool takeQueueItem();
public:
	TranslatorToXml(ErrorQueue* errorQueue,	Queue* responseQueue, Queue* entityQueue);
	~TranslatorToXml();
	void start();
	void stop();
};

