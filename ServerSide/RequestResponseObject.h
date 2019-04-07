#pragma once
#include "SFML/Network.hpp"
#include "Client.h"
#include <iostream>

class Client;

class RequestResponseObject
{
	std::string content;
	Client* client;
	unsigned int conversationIndex;
	bool correct = false;

	RequestResponseObject();
public:
	~RequestResponseObject();
	bool isCorrect();
	void setConversationIndex(unsigned int index);
	static RequestResponseObject* unpackPacket(sf::Packet& packet);
	std::string* getRequest();
};

