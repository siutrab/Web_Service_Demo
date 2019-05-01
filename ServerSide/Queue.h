#pragma once
#include <iostream>
#include <queue>
#include <iterator>
#include "Queue.h"

using std::queue;
using std::shared_ptr;

class QueueItem;


class Queue
{
protected:
	queue<shared_ptr<QueueItem>> itemQueue;
public:
	Queue() {}
	~Queue() {}
	bool isEmpty() 
	{
		if (itemQueue.size() == 0) return true;
		else return false;
	}

	void addItem(shared_ptr<QueueItem> item)
	{
		itemQueue.push(item);
	}

	shared_ptr<QueueItem> getItem()
	{
		shared_ptr<QueueItem> item = itemQueue.front();
		itemQueue.pop();
		return item;
	}
};