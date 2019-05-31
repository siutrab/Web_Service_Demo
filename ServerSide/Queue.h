#pragma once
#include "Queue.h"
#include "QueueItem.h"
#include <iostream>
#include <utility>
#include <queue>
#include <iterator>

using std::queue;
using std::unique_ptr;

class QueueItem;
class Client;

class Queue
{
protected:
	queue<unique_ptr<QueueItem>> itemQueue;
public:
	Queue();

	~Queue() {}

	bool isEmpty();		// returns true if queue is empty or if the first element belongs to disconnected client
	void addItem(unique_ptr<QueueItem> item);
	unique_ptr<QueueItem> getItem();
};