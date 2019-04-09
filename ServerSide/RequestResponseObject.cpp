#include "pch.h"
#include "RequestResponseObject.h"


	RequestResponseObject::RequestResponseObject(Client& client)
		: clientIndex(client.getIndex())
	{	}

	RequestResponseObject::~RequestResponseObject()
	{	}

	RequestResponseObject* RequestResponseObject::unpackPacket(sf::Packet& packet, Client& client)
	{
		RequestResponseObject* requestResponse = new RequestResponseObject(client);

		if (packet >> requestResponse->content)
			requestResponse->correct = true;

		return requestResponse;
	}

	bool RequestResponseObject::isCorrect() { return correct; }
	std::string* RequestResponseObject::getRequest() { return &content; }
// Setters
	//void RequestResponseObject::setConversationIndex(unsigned int index) { this->conversationIndex = index; }