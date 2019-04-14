#include "pch.h"
#include "RequestsQueue.h"

RequestsQueue::RequestsQueue()
	:	requestsQueue()
{
	Client::setRequestQueuePtr(this);
}

RequestsQueue::~RequestsQueue()
{	}

void RequestsQueue::addRequest(Request* request)
{
	requestsQueue.push(request);
	//std::cout << *(request->getRequest()) << std::endl;
}

Request* RequestsQueue::getRequest()
{
	Request* request = requestsQueue.front();
	requestsQueue.pop();
	return request;
}

bool RequestsQueue::isEmpty()
{
	if (requestsQueue.size() == 0) return true;
	else return false;
}