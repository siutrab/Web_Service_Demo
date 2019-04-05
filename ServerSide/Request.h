#pragma once
#include "SFML/Network.hpp"
#include "Client.h"
class Client;
class Request
{
	std::string content;
	Client* client;
	unsigned int conversationIndex;
	bool correct = false;

	Request();
public:
	~Request();
	bool isCorrect();
	void setConversationIndex(unsigned int index);
	static Request* unpackPacket(sf::Packet& packet);
};

