#pragma once
#include "MethodInterface.h"
#include "SFML/Network/TcpSocket.hpp"
#include "SFML/Network/TcpListener.hpp"
#include "SFML/Network/Packet.hpp"
#include <thread>
#include <exception>
#include <iostream>
#include <vector>

using std::vector;
using std::thread;
using std::string;
using std::cout;
using std::endl;


class ConnectionHandler
{
	static string disconnectMessage;

		static unsigned int requestNumber;
		unsigned int port;
		sf::IpAddress ipAddress;
		sf::TcpSocket socket;

	void connect();
	void disconnect();
	void handleReceivedData(sf::Packet& packet, MethodInterface* method);	// unpacks the message and calls printing method
public:
	ConnectionHandler(unsigned int port, sf::IpAddress ip = sf::IpAddress::getLocalAddress());
	~ConnectionHandler();
	bool sendData(string& message);						// sends string through the web service
	void waitForResponse(MethodInterface* method);		// Waits until response and prints it on the console screen
	static unsigned int getRequestNumber();				// returns unique number of request for this client
};

