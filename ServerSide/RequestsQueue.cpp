#include "pch.h"
#include "RequestsQueue.h"


RequestsQueue::RequestsQueue()
	: queuOfRequests()
{
}


RequestsQueue::~RequestsQueue()
{
}

void RequestsQueue::addConversation(Conversation* conversation)
{
	queuOfRequests.push(conversation);
	getConversation();
}

Conversation* RequestsQueue::getConversation()
{
	Conversation* conversation = queuOfRequests.front();
	std::cout << *(conversation->getRequest()) << std::endl;
	queuOfRequests.pop();
	return conversation;
}