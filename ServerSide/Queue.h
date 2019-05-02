#pragma once
#include <iostream>
#include <queue>
#include <iterator>
#include "Queue.h"

using std::queue;
using std::shared_ptr;
using std::unique_ptr;

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

	void addItem(QueueItem& item)
	{
		//itemQueue.push(unique_ptr<QueueItem>(&item));
		unique_ptr<QueueItem>itemMove(&item);
		//itemMove = std::move(itemQueue.back());
		itemQueue.push(std::move(itemMove));
	}

	QueueItem* getItem()
	{
		QueueItem* item = itemQueue.front().release();
		itemQueue.pop();
		return item;

		//unique_ptr<QueueItem> itemMove = std::move(itemQueue.front());
		//itemQueue.pop();
		//return itemMove.release();

		unique_ptr<QueueItem>itemPtr();
		 itemQueue.pop( std::move(itemPtr));

		
	}
};