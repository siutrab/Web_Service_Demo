#pragma once
//#include "Router.h"
#include "SFML/Network.hpp"

using sf::TcpListener;
using sf::TcpSocket;
using sf::SocketSelector;


class Router;
class ConnectedClientsMenager;

	class Listener
	{
			TcpListener tcpListener;
			SocketSelector* const selector;
			ConnectedClientsMenager* const clientsList;
	public:
		Listener(Router* router);
		~Listener();
		void listen();
	};

