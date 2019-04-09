#include "pch.h"
#include "RequestsQueue.h"

RequestsQueue::RequestsQueue()
	:	requestsQueue()
{
	Client::setRequestQueuePtr(this);
}

RequestsQueue::~RequestsQueue()
{
}

void RequestsQueue::addRequest(RequestResponseObject* conversation)
{
	requestsQueue.push(conversation);
	std::cout << *(conversation->getRequest()) << std::endl;
}

RequestResponseObject* RequestsQueue::getRequest()
{
	RequestResponseObject* conversation = requestsQueue.front();
	
	requestsQueue.pop();
	return conversation;
}
