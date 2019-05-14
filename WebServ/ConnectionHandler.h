#pragma once
#include "SFML/Network/TcpSocket.hpp"
#include "SFML/Network/TcpListener.hpp"
#include "SFML/Network/Packet.hpp"
#include <thread>
#include <exception>
#include <iostream>

using std::thread;
using std::string;

class ConnectionHandler
{
		thread CONNECTION_HANDLER_THREAD;
		bool running;

		unsigned int port;
		sf::IpAddress ipAddress;
		sf::TcpSocket socket;
	
	void listen();
	void run();
	void handleReceivedData(sf::Packet& packet);
public:
	ConnectionHandler(unsigned int port, sf::IpAddress ip = sf::IpAddress::getLocalAddress());
	~ConnectionHandler();
	bool start();
	bool sendData(string& message);
};

