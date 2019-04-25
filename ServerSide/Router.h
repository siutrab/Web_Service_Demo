#pragma once
#include "ConnectedClientsList.h"
#include "Listener.h"
#include "SFML/Network.hpp"
#include <thread>


using sf::SocketSelector;
using std::unique_ptr;
using std::thread;

	class Router
	{
			thread ROUTER_THREAD;
			bool running = false;
			const unsigned int port;

			SocketSelector selector;
			ConnectedClientsList clientsList;
			Listener listener;

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
