#ifndef QUEUE_TEMPLATE_H
#define QUEUE_TEMPLATE_H



#pragma once
#include <iostream>
#include <queue>
#include <iterator>


using std::queue;


template<typename T>
class Queue
{
protected:
	queue<T*> itemQueue;
public:
	Queue() {}
	~Queue() {}
	bool isEmpty() 
	{
		if (itemQueue.size() == 0) return true;
		else return false;
	}

	void addItem(T& item)
	{
		itemQueue.push(&item);
	}

	T& getItem() 
	{
		T& item = itemQueue.front();
		itemQueue.pop();
		return item;
	}
};

#endif // !QUEUE_TEMPLATE_H
