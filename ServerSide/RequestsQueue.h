#pragma once
#include <queue>
#include <iterator>
#include "RequestResponseObject.h"

class RequestResponseObject;

	class RequestsQueue
	{
			static RequestsQueue* requestsQueuePointer;
			std::queue<RequestResponseObject*> requestsQueue;

		// Methods
		static void setRequestsQueuePtr(RequestsQueue* pointer);
	public:
		RequestsQueue();
		~RequestsQueue();
		void addConversation(RequestResponseObject* conversation);
		RequestResponseObject* getConversation();
		static RequestsQueue* getRequestsQueuePtr();
	};