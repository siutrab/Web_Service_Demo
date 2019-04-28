#pragma once
#include "SFML/Network.hpp"
#include "Client.h"
#include <iostream>
#include <memory>
#include "QueueItem.h"

using std::shared_ptr;
using std::string;
using sf::Packet;

class Client;


class Request
	: public QueueItem<string>
{
		//string content;
		//Client* const clientPointer;
		bool correct = false;
	
	Request(Client* client, string& content);
public:
	~Request();
	bool isCorrect();
	static shared_ptr<Request> unpackPacket(Packet& packet, Client* client);
	//string& getContent();
};
