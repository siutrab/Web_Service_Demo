#pragma once
#include "SFML/Network/TcpSocket.hpp"
#include "SFML/Network/TcpListener.hpp"
#include <thread>

using std::thread;

class ConnectionHandler
{
	thread CONNECTION_HANDLER_THREAD;

	sf::TcpSocket socket;
	sf::TcpListener listener;
	
	void listen();
public:
	ConnectionHandler();
	~ConnectionHandler();
};

