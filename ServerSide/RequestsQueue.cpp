#include "pch.h"
#include "RequestsQueue.h"

RequestsQueue* RequestsQueue::requestsQueuePointer = nullptr;

RequestsQueue::RequestsQueue()
	:	requestsQueue()
{
	RequestsQueue::setRequestsQueuePtr(this);
}


RequestsQueue::~RequestsQueue()
{
}

void RequestsQueue::addConversation(RequestResponseObject* conversation)
{
	requestsQueue.push(conversation);
	getConversation();
}

RequestResponseObject* RequestsQueue::getConversation()
{
	RequestResponseObject* conversation = requestsQueue.front();
	std::cout << *(conversation->getRequest()) << std::endl;
	requestsQueue.pop();
	return conversation;
}

RequestsQueue* RequestsQueue::getRequestsQueuePtr() { return RequestsQueue::requestsQueuePointer; }
void RequestsQueue::setRequestsQueuePtr(RequestsQueue* requestsQueue) { RequestsQueue::requestsQueuePointer = requestsQueue; }