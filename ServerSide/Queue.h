#pragma once
#include <iostream>
#include <utility>
#include <queue>
#include <iterator>
#include "Queue.h"
#include "QueueItem.h"

using std::queue;
using std::shared_ptr;
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

	void addItem(QueueItem& item)
	{
		//itemQueue.push(unique_ptr<QueueItem>(&item));
		//itemMove = std::move(itemQueue.back());
		
		//auto itemMove = unique_ptr<QueueItem>(&item);
		//unique_ptr<QueueItem> ptr;
		//ptr.reset(&item);
		unique_ptr<QueueItem> itemPtr(&item);
		itemQueue.push(std::move(itemPtr));
	}

	QueueItem* getItem()
	{
		QueueItem* itemPtr = itemQueue.front().release();
		itemQueue.pop();
		return itemPtr;

		/*auto_ptr<QueueItem> itemAutoPtr = itemQueue.front();
		QueueItem* itemPtr = itemAutoPtr.release();
		itemQueue.pop();
		return itemPtr;*/
								
								
		/*QueueItem* item = itemQueue.front().release();
		itemQueue.pop();
		return item;*/

		//unique_ptr<QueueItem> itemMove = std::move(itemQueue.front());
		//itemQueue.pop();
		//return itemMove.release();

		/*unique_ptr<QueueItem>itemPtr();
		 itemQueue.pop( std::move(itemPtr));*/

		
	}
};