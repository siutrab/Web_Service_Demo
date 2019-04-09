#pragma once
#include "SFML/Network.hpp"
#include "ConnectedClientsList.h"
#include "Listener.h"

class ConnectedClientsList;
class Listener;
class Server;

	class Router
	{
		bool running = false;
		const unsigned int port;
		sf::SocketSelector selector;

		ConnectedClientsList* const clientsList;	// owner
		Listener* const listener;					// owner
	public:
			Router(const unsigned int port);
			~Router();
			void start();
			void stop();
			unsigned int getPort();
			sf::SocketSelector* getSelector();
			ConnectedClientsList* getClientsList();
	};