#pragma once
#include "SFML/Network.hpp"
#include "ConnectedClientsList.h"
#include "Listener.h"
//#include "C:\CPP Libraries\SFML 2.3\SFML-2.3\include\SFML\Network.hpp"

class ConnectedClientsList;
class Listener;

class Router
{
	bool running = false;
	unsigned int port;
	sf::SocketSelector selector;

	ConnectedClientsList* clientsList;
	Listener* listener;
public:
	Router(unsigned int port);
	~Router();
	void start();
	void stop();
	unsigned int getPort();
	sf::SocketSelector* getSelector();
	ConnectedClientsList* getClientsList();
};

