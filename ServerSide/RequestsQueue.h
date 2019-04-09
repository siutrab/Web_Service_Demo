#pragma once
#include <queue>
#include <iterator>
#include "RequestResponseObject.h"

class RequestResponseObject;

	class RequestsQueue
	{
			std::queue<RequestResponseObject*> requestsQueue;
	public:
		RequestsQueue();
		~RequestsQueue();
		void addRequest(RequestResponseObject* conversation);
		RequestResponseObject* getRequest();
	};