#include "pch.h"
#include "RequestsQueue.h"


RequestsQueue::RequestsQueue()
{
}


RequestsQueue::~RequestsQueue()
{
}

void RequestsQueue::addConversation(Conversation* conversation)
{
	requestQueue.push(conversation);
	getConversation();
}

Conversation* RequestsQueue::getConversation()
{
	Conversation* conversation = requestQueue.front();
	requestQueue.pop();
	std::cout << conversation->getRequest() << std::endl;
	return conversation;
}