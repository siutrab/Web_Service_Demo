#pragma once
#include <iostream>
#include <queue>
#include <iterator>
#include "QueueItem.h"

using std::queue;

template<typename> class QueueItem;

template<typename T>
class Queue
{
protected:
	queue<shared_ptr<T>> itemQueue;
public:
	Queue() {}
	~Queue() {}
	bool isEmpty() 
	{
		if (itemQueue.size() == 0) return true;
		else return false;
	}

	void addItem(shared_ptr<T> item)
	{
		itemQueue.push(item);
	}

	shared_ptr<T> getItem() 
	{
		shared_ptr<T> item = itemQueue.front();
		itemQueue.pop();
		return item;
	}
};