#pragma once
#include "ClientsMenager.h"
#include "Listener.h"
#include "SFML/Network.hpp"
#include <thread>


using sf::SocketSelector;
using std::unique_ptr;
using std::thread;

	class Router
	{
		
			bool running;
			const unsigned int port;
			thread ROUTER_THREAD;

			SocketSelector selector;
			ClientsMenager clientsList;
			Listener listener;

		void run();							// thread main loop
	public:
		Router(const unsigned int port);
		~Router();
		void start();						// begins new thread
		void stop();						// joins thread
		unsigned int getPort();
		SocketSelector* getSelector();
		ClientsMenager* getClientsList();
	};
