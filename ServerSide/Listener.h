#pragma once
#include "SFML/Network.hpp"
#include "ConnectedClientsList.h"
#include "Router.h"

class Router;
class ConnectedClientsList;

	class Listener
	{
			static Listener* listenerPointer;
			sf::TcpListener tcpListener;
			sf::SocketSelector* selector;
			ConnectedClientsList* clientsList;
		static void setListenerPointer(Listener* pointer);
	public:
		Listener(Router& router);
		~Listener();
		void listen();
		static Listener* getListenrPointer();
	};

