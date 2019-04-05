#pragma once
#include "ConnectedClientsList.h"
#include "Listener.h"
#include "SFML/Network.hpp"
class Router
{
	bool running = false;
	unsigned int port;
	sf::SocketSelector selector;

	ConnectedClientsList clientsList;
	Listener listener;
public:
	Router(unsigned int port);
	~Router();
	void start();
	void stop();
};

