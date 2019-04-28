#include "pch.h"
#include "RequestQueue.h"

RequestQueue::RequestQueue()

{
	Client::setRequestQueuePtr(this);
	TranslatorXml::setRequestQueuePtr(this);
}

RequestQueue::~RequestQueue()
{}