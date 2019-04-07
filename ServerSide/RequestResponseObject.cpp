#include "pch.h"
#include "RequestResponseObject.h"


	RequestResponseObject::RequestResponseObject()
	{	}

	RequestResponseObject::~RequestResponseObject()
	{	}

	RequestResponseObject* RequestResponseObject::unpackPacket(sf::Packet& packet)
	{
		RequestResponseObject* conversation = new RequestResponseObject();

		if (packet >> conversation->content)
			conversation->correct = true;

		return conversation;
	}

	bool RequestResponseObject::isCorrect() { return correct; }
	std::string* RequestResponseObject::getRequest() { return &content; }
// Setters
	void RequestResponseObject::setConversationIndex(unsigned int index) { this->conversationIndex = index; }