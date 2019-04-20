#pragma once
#include <iostream>
#include <queue>
#include <iterator>
#include "Request.h"

using std::queue;

class Request;

	class RequestsQueue
	{
			queue<Request*> requestsQueue;
	public:
		RequestsQueue();
		~RequestsQueue();
		bool isEmpty();
		void addRequest(Request* conversation);
		Request* getRequest();
	};