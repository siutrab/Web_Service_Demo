#pragma once
#include "SFML/Network.hpp"
#include "ConnectedClientsList.h"
#include "Listener.h"
#include <thread>


//class ConnectedClientsList;
class Listener;
class Server;


using sf::SocketSelector;
using std::unique_ptr;
using std::thread;

	class Router
	{
			thread ROUTER_THREAD;
			bool running = false;
			const unsigned int port;
			SocketSelector selector;

			unique_ptr<ConnectedClientsList> clientsList;	// owner
			unique_ptr<Listener> const listener;					// owner
		void run();
	public:
		Router(const unsigned int port);
		~Router();
		void start();
		void stop();
		unsigned int getPort();
		SocketSelector* getSelector();
		ConnectedClientsList* getClientsList();
	};