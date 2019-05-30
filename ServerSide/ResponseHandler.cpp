#include "ResponseHandler.h"



ResponseHandler::ResponseHandler(Queue* responseQueue, ErrorHandler* errorQueue)
	:	responseQueuePtr(responseQueue),
		errorQueuePtr(errorQueue),
		running(false)
{	}


ResponseHandler::~ResponseHandler()
{
	stop();
}

void ResponseHandler::start()
{
	running = true;
	RESPONSE_HANDLER_THREAD = thread(&ResponseHandler::run, this);
}


void ResponseHandler::run()
{
	while (running)
	{
		if (!responseQueuePtr->isEmpty())
			sendResponse();
	}
}


void ResponseHandler::sendResponse()
{
	auto queueItem = responseQueuePtr->getItem();
	auto client = queueItem->getClientPointer();
	auto content = queueItem->getContent();
	string* contentString = static_cast<string*>(content);
			
	client->sendResponse(contentString);
}


void ResponseHandler::stop()
{
	running = false;
	if (RESPONSE_HANDLER_THREAD.joinable())
		RESPONSE_HANDLER_THREAD.join();
}
