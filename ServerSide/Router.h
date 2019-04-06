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
		unsigned int port;
		sf::SocketSelector selector;

		ConnectedClientsList* clientsList;	// owner
		Listener* listener;					// owner
		Server* server;						// parent element pointer
	public:
			Router(unsigned int port);
			~Router();
			void start();
			void stop();
			unsigned int getPort();
			sf::SocketSelector* getSelector();
			ConnectedClientsList* getClientsList();
	};