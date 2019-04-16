#pragma once
#include "SFML/Network.hpp"
#include "Client.h"

using std::string;
using sf::Packet;

class Client;

class Request
{
		string content;
		Client* const clientPointer;
		bool correct = false;
	
	Request(Client& client);
public:
	~Request();
	bool isCorrect();
	static Request* unpackPacket(Packet& packet, Client& client);
	string* getRequest();
};
