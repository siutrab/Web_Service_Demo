#pragma once
#include <iostream>
#include <utility>
#include <queue>
#include <iterator>
#include "Queue.h"
#include "QueueItem.h"

using std::queue;
//using std::shared_ptr;
using std::unique_ptr;
using std::auto_ptr;

class QueueItem;

class Queue
{
protected:
	queue<unique_ptr<QueueItem>> itemQueue;
public:
	Queue()
		: itemQueue()
	{}
	~Queue() {}
	bool isEmpty() 
	{
		if (itemQueue.size() == 0) return true;
		else return false;
	}

	void addItem(unique_ptr<QueueItem> item)
	{
		itemQueue.push(std::move(item));
	}

	unique_ptr<QueueItem> getItem()
	{
		unique_ptr<QueueItem>& pointerReference = itemQueue.front();
		
		unique_ptr<QueueItem> newReference(pointerReference.release());
		itemQueue.pop();

		return std::move(newReference);
	}
};