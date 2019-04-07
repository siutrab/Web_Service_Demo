#pragma once
#include "SFML/Network.hpp"
#include "Client.h"
#include <iostream>
class Client;

class Conversation
{
	std::string content;
	Client* client;
	unsigned int conversationIndex;
	bool correct = false;

	Conversation();
public:
	~Conversation();
	bool isCorrect();
	void setConversationIndex(unsigned int index);
	static Conversation* unpackPacket(sf::Packet& packet);
	std::string* getRequest();
};

