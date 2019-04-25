#ifndef LISTENER_H
#define LISTENER_H

#pragma once
#include "SFML/Network.hpp"


using sf::TcpListener;
using sf::TcpSocket;
using sf::SocketSelector;


class Router;
class ConnectedClientsList;

	class Listener
	{
			TcpListener tcpListener;
			SocketSelector* const selector;
			ConnectedClientsList* const clientsList;
	public:
		Listener(Router* router);
		~Listener();
		void listen();
	};


#endif // !LISTENER_H
