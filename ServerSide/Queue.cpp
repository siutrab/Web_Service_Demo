#include "pch.h"
#include "Queue.h"
#include "Client.h"

Queue::Queue()
	: itemQueue()
{}

bool Queue::isEmpty()
{
	if (itemQueue.size() == 0) return true;
	else
	{
		unique_ptr<QueueItem>& item = itemQueue.front();
		Client* client = item->getClientPointer();
		if (client->isConnected())
			return false;
		else
		{
			item.~unique_ptr();
			return true;
		}
	}
}

void Queue::addItem(unique_ptr<QueueItem> item)
{
	itemQueue.push(std::move(item));
}

unique_ptr<QueueItem> Queue::getItem()
{
	unique_ptr<QueueItem>& pointerReference = itemQueue.front();

	unique_ptr<QueueItem> newReference(pointerReference.release());
	itemQueue.pop();

	return std::move(newReference);
}
