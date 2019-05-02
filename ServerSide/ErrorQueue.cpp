#include "ErrorQueue.h"



ErrorQueue::ErrorQueue()
{
	Client::setErrorQueuePtr(this);

}


ErrorQueue::~ErrorQueue()
{
}

void ErrorQueue::addItem(QueueItem& item, ExceptionInterface& exception)
{
	ErrorResponse errorResponse(exception.getValue());
	ContentInterface& contentInterface = dynamic_cast<ContentInterface&>(errorResponse);
	item.changeContent(contentInterface);

	auto itemPointer = unique_ptr<QueueItem>(&item);
	itemQueue.push(itemPointer);
}

