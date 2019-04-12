#pragma once
#include "SFML/Network.hpp"
#include "Client.h"

class Client;

class Request
{
		std::string content;
		Client* const clientPointer;
		bool correct = false;
	
	Request(Client& client);
public:
	~Request();
	bool isCorrect();
	static Request* unpackPacket(sf::Packet& packet, Client& client);
	std::string* getRequest();
};
