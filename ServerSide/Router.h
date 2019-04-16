#pragma once
#include "SFML/Network.hpp"
#include "ConnectedClientsList.h"
#include "Listener.h"

class ConnectedClientsList;
class Listener;
class Server;

using sf::SocketSelector;

	class Router
	{
			bool running = false;
			const unsigned int port;
			SocketSelector selector;

			ConnectedClientsList* const clientsList;	// owner
			Listener* const listener;					// owner
	public:
		Router(const unsigned int port);
		~Router();
		void start();
		void stop();
		unsigned int getPort();
		SocketSelector* getSelector();
		ConnectedClientsList* getClientsList();
	};