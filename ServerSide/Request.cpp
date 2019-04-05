#include "pch.h"
#include "Request.h"


Request::Request()
{
}


Request::~Request()
{
}

Request* Request::unpackPacket(sf::Packet& packet)
{
	Request* message = new Request();
	std::string msgContent = message->content;
	if (packet >> message->content) message->correct = true;
	return message;
}

bool Request::isCorrect() { return correct; }

// Setters
void Request::setConversationIndex(unsigned int index) { this->conversationIndex = index; }