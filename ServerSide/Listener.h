#pragma once
#include "SFML/Network.hpp"
#include "ConnectedClientsList.h"
#include "Router.h"

class Router;
class ConnectedClientsList;

class Listener
{
	sf::TcpListener listener;
	sf::SocketSelector* selector;
	ConnectedClientsList* clientsList;
public:
	//Listener(unsigned int port, sf::SocketSelector& selector, ConnectedClientsList& clientsList);
	Listener(Router& router);
	~Listener();
	void listen();
};

