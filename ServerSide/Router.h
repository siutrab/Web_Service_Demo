#pragma once
#include "SFML/Network.hpp"
#include "ConnectedClientsList.h"
#include "Listener.h"

class ConnectedClientsList;
class Listener;

class Router
{
	bool running = false;
	unsigned int port;
	sf::SocketSelector selector;

	ConnectedClientsList* clientsList;	// owner
	Listener* listener;		// owner
public:
	Router(unsigned int port);
	~Router();
	void start();
	void stop();
	unsigned int getPort();
	sf::SocketSelector* getSelector();
	ConnectedClientsList* getClientsList();
};

