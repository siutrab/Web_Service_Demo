#pragma once
#include <iostream>
#include <queue>
#include <iterator>
#include "Request.h"

class Request;

	class RequestsQueue
	{
			std::queue<Request*> requestsQueue;
	public:
		RequestsQueue();
		~RequestsQueue();
		bool isEmpty();
		void addRequest(Request* conversation);
		Request* getRequest();		// returns the first element of queue or nullptr if the queue is empty
	};