#pragma once
#include "SFML/Network.hpp"
#include "Client.h"
#include <iostream>

class Client;

class RequestResponseObject
{
	std::string content;
	const unsigned int clientIndex;
	bool correct = false;

	RequestResponseObject(Client& client);
public:
	~RequestResponseObject();
	bool isCorrect();
	//void setConversationIndex(const unsigned int index);
	static RequestResponseObject* unpackPacket(sf::Packet& packet, Client& client);
	std::string* getRequest();
};

