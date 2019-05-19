#pragma once
#include "Queue.h"
#include "ErrorQueue.h"
#include "Client.h"
#include <thread>

using std::unique_ptr;
using std::thread;
using std::string;

class ResponseHandler
{
	thread REQUEST_HANDLER_THREAD;
	bool running;

		Queue* responseQueuePtr;
		ErrorQueue* errorQueuePtr;

	void run();
	void sendResponse();
	void sendErrorMessage();
public:
	ResponseHandler(Queue* responseQueue, ErrorQueue* errorQueue);
	~ResponseHandler();
	void start();
	void stop();
};

