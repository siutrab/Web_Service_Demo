#pragma once
#include <queue>
#include "Conversation.h"

class Conversation;

	class RequestsQueue
	{
		std::queue<Conversation*> queuOfRequests;
	public:
		RequestsQueue();
		~RequestsQueue();
		void addConversation(Conversation* conversation);
		Conversation* getConversation();
	};