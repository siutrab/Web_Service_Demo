#include "ErrorQueue.h"



ErrorQueue::ErrorQueue()
{
	Client::setErrorQueuePtr(this);

}


ErrorQueue::~ErrorQueue()
{
}

void ErrorQueue::addItem(unique_ptr<QueueItem> item, ExceptionInterface& exception)
{
	unique_ptr<ContentInterface> errorResponse = std::make_unique<ErrorResponse>(exception.getValue());
	//ContentInterface& contentInterface = dynamic_cast<ContentInterface&>(errorResponse);
	item->changeContent(errorResponse);

	//unique_ptr<QueueItem> itemPointer = std::make_unique<QueueItem>(&item);
	itemQueue.push(std::move(item));
}

