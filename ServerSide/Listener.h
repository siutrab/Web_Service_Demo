#pragma once
#include "SFML/Network.hpp"
#include "ConnectedClientsList.h"

class Listener
{
	sf::TcpListener listener;
	sf::SocketSelector& selector;
	ConnectedClientsList& clientsList;
public:
	Listener(unsigned int port, sf::SocketSelector& selector, ConnectedClientsList& clientsList);
	~Listener();
	void listen();
};

