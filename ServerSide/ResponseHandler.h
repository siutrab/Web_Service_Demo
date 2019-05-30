#pragma once
#include "Queue.h"
#include "ErrorHandler.h"
#include "Client.h"
#include <thread>

using std::unique_ptr;
using std::thread;
using std::string;

class ResponseHandler
{
	thread RESPONSE_HANDLER_THREAD;
	bool running;

		Queue* responseQueuePtr;
		ErrorHandler* errorQueuePtr;

	void run();				// main loop
	void sendResponse();	// Sends response that is first in Queue
public:
	ResponseHandler(Queue* responseQueue, ErrorHandler* errorQueue);
	~ResponseHandler();

	void start();
	void stop();
};

