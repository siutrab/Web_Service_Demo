#pragma once
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
		thread CONNECTION_HANDLER_THREAD;
		bool running;

		vector<string> responeBuffer;

		static unsigned int requestNumber;
		unsigned int port;
		sf::IpAddress ipAddress;
		sf::TcpSocket socket;


	void run();
	void handleReceivedData(sf::Packet& packet);
public:
	ConnectionHandler(unsigned int port, sf::IpAddress ip = sf::IpAddress::getLocalAddress());
	~ConnectionHandler();
	bool start();
	bool sendData(string& message);
	static unsigned int getRequestNumber();
	bool stop();
	bool printResponseMessages();
	bool responseBufferIsEmpty();
};

