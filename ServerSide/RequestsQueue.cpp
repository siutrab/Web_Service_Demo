#include "pch.h"
#include "RequestsQueue.h"

RequestsQueue::RequestsQueue()

{
	Client::setRequestQueuePtr(this);
	RequestHandler::setRequestQueuePointer(this);
}
