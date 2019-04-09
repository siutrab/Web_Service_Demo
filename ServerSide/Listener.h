#pragma once
#include "SFML/Network.hpp"
#include "ConnectedClientsList.h"
#include "Router.h"

class Router;
class ConnectedClientsList;

	class Listener
	{
			sf::TcpListener tcpListener;
			sf::SocketSelector* const selector;
			ConnectedClientsList* const clientsList;
	public:
		Listener(Router& router);
		~Listener();
		void listen();
	};

