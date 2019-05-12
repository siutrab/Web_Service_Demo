#pragma once
#include <thread>
#include "Queue.h"
#include "Client.h"

using std::unique_ptr;
using std::thread;
using std::string;

class ResponseHandler
{
	thread REQUEST_HANDLER_THREAD;
	bool running;

		Queue* responseQueuePtr;

	void run();
public:
	ResponseHandler(Queue* responseQueue);
	~ResponseHandler();
	void start();
	void stop();
};

