#pragma once
#include "SFML/Network.hpp"

using sf::TcpListener;
using sf::TcpSocket;
using sf::SocketSelector;

class Router;
class ClientsMenager;

	class Listener
	{
			TcpListener tcpListener;
			SocketSelector* const selector;
			ClientsMenager* const clientsList;
	public:
		Listener(Router* router);
		~Listener();
		void listen();			// Listen on port for new connection calls
	};

