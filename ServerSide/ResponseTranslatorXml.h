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

class ResponseTranslatorXml
{
	bool running;

	thread TRANSLATOR_TO_XML_THREAD;
	ErrorQueue* errorQueue;
	Queue* responseQueue;
	Queue* sqlResultQueue;

		unique_ptr<QueueItem> queueItem;
		unique_ptr<ResultSetContent> content;
		ReadMethodInterface* method;
		shared_ptr<ResultSet> resultSet;

		unique_ptr<DocumentXml> document;
	
	void run();
	bool takeQueueItem();
	unique_ptr<string> generateXmlDocument();
	void pushResponseOnQueue(unique_ptr<string> xmlDocument);
	void setQueueItem();
	void setMethod();
	void setContent();
	void setResultSet();
public:
	ResponseTranslatorXml(ErrorQueue* errorQueue,	Queue* responseQueue, Queue* sqlResultQueue);
	~ResponseTranslatorXml();
	void start();
	void stop();
};

