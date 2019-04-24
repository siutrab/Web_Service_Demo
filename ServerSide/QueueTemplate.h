#pragma once
#include <iostream>
#include <queue>
#include <iterator>
//#include "Server.h"

using std::queue;

//class Server;

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

