#include "pch.h"
#include "RequestsQueue.h"

RequestQueue::RequestQueue()

{
	Client::setRequestQueuePtr(this);
	RequestHandler::setRequestQueuePointer(this);
}

RequestQueue::~RequestQueue()
{}