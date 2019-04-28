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
	Request(Client* client, string& content);
public:
	~Request();
	static shared_ptr<Request> unpackPacket(Packet& packet, Client* client);
};
