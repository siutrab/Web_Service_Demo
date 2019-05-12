#include "ErrorQueue.h"



ErrorQueue::ErrorQueue()
{
	//Client::setErrorQueuePtr(this);
	//TranslatorXml::setErrorQueuePtr(this);
}


ErrorQueue::~ErrorQueue()
{
}

void ErrorQueue::addItem(unique_ptr<QueueItem> item, ExceptionInterface& exception)
{
	auto errorMessage = std::make_unique<string>(exception.getValue());
	unique_ptr<ContentInterface> errorResponse = std::make_unique<ErrorResponse>(*errorMessage);
	item->changeContent(errorResponse);
	itemQueue.push(std::move(item));
}

