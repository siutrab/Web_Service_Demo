#pragma once
#include "SFML/Network.hpp"
#include "QueueItem.h"
#include "Client.h"
#include <iostream>
#include <memory>
#include <string>


using std::shared_ptr;
using std::string;
using sf::Packet;

class Client;



class Request
	: public Content<string>
{
public:
	Request(string& content);
	~Request();
	//static shared_ptr<Request> unpackPacket(Packet& packet, Client* client);
};
