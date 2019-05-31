#pragma once
#include "DocumentXml.h"
#include "ErrorHandler.h"
#include "MethodInterface.h"
#include "EntityInterface.h"
#include "ResultSetContent.h"
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
	ErrorHandler* errorHandler;
	Queue* responseQueue;
	Queue* sqlResultQueue;

		unique_ptr<QueueItem> queueItem;
		unique_ptr<ResultSetContent> content;
		ReadMethodInterface* method;
		shared_ptr<ResultSet> resultSet;

		unique_ptr<DocumentXml> document;
	
	void run();					// thread main loop
	bool takeQueueItem();		// takes first item from queue and initializes all fields in class (like queueItem and content etc)
	void setQueueItem();		// initilizes queueItem field
	void setContent();			// initializes content field
	void setMethod();			// initializes method field
	void setResultSet();		// initializes resultSet field
	unique_ptr<string> generateXmlDocument();	// generates XML as string
	void pushResponseOnQueue(unique_ptr<string> xmlDocument);	// pushes queueItem on queue that makes class ready to tke another item
public:
	ResponseTranslatorXml(ErrorHandler* errorQueue,	Queue* responseQueue, Queue* sqlResultQueue);
	~ResponseTranslatorXml();
	void start();				// starsts the thread
	void stop();				// joins the thread
};

