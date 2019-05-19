#include "ResponseHandler.h"



ResponseHandler::ResponseHandler(Queue* responseQueue, ErrorQueue* errorQueue)
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
	REQUEST_HANDLER_THREAD = thread(&ResponseHandler::run, this);
}


void ResponseHandler::run()
{
	while (running)
	{
		if (!responseQueuePtr->isEmpty())
			sendResponse();

		if (!errorQueuePtr->isEmpty())
			sendErrorMessage();
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


void ResponseHandler::sendErrorMessage()
{
	auto queueItem = errorQueuePtr->getItem();
	auto client = queueItem->getClientPointer();
	auto content = queueItem->getContent();
	string* contentString = static_cast<string*>(content);

	client->sendResponse(contentString);
}


void ResponseHandler::stop()
{
	if (REQUEST_HANDLER_THREAD.joinable())
	{
		running = false;
		REQUEST_HANDLER_THREAD.join();
	}
}
