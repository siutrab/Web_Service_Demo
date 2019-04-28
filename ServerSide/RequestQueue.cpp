#include "pch.h"
#include "RequestQueue.h"

RequestQueue::RequestQueue()

{
	Client::setRequestQueuePtr(this);
	//RequestHandler::setRequestQueuePointer(this);
	TranslatorXml::setRequestQueuePtr(this);
}

RequestQueue::~RequestQueue()
{}