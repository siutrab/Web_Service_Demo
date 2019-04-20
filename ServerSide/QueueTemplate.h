#pragma once
#include <iostream>
#include <queue>
#include <iterator>
#include "Server.h"

using std::queue;

class Server;

template<typename T>
class Queue
{
	queue<T*> itemQueue;
public:
	Queue();
	~Queue();
	bool isEmpty();
	void addItem(T* item);
	T* getItem();
};

