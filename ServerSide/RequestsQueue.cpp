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

// returns the first element of queue or nullptr if the queue is empty
Request* RequestsQueue::getRequest()
{
	if (requestsQueue.size() > 0)
	{
		Request* request = requestsQueue.front();
		requestsQueue.pop();
		return request;
	}
	else return nullptr;
}
