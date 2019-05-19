#include "ResponseHandler.h"



ResponseHandler::ResponseHandler(Queue* responseQueue, ErrorQueue* errorQueue)
	:	responseQueuePtr(responseQueue),
		running(false)
{
}


ResponseHandler::~ResponseHandler()
{
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
		if (responseQueuePtr->isEmpty())
		{

		}
		else
		{
			auto queueItem = responseQueuePtr->getItem();
			auto client = queueItem->getClientPointer();
			auto content = queueItem->getContent();
			string* contentString = static_cast<string*>(content);
			
			client->sendResponse(contentString);
		}
	}
}
void ResponseHandler::stop()
{
	REQUEST_HANDLER_THREAD.join();
	running = false;
}
