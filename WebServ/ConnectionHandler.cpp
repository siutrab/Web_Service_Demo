#include "pch.h"
#include "ConnectionHandler.h"


ConnectionHandler::ConnectionHandler(unsigned int port, sf::IpAddress ip)
	:	socket(),
		running(false),
		ipAddress()
{
	this->port = port;
	ipAddress = ip;	
}


ConnectionHandler::~ConnectionHandler()
{
	if(CONNECTION_HANDLER_THREAD.joinable())
		CONNECTION_HANDLER_THREAD.join();
}

bool ConnectionHandler::start()
{
	if (socket.connect(ipAddress, port) != sf::Socket::Done)
		return false;
	else
	{
		running = true;
		CONNECTION_HANDLER_THREAD = thread(&ConnectionHandler::run, this);
		return true;
	}
}

void ConnectionHandler::run()
{
	sf::Packet packet;

	while (running)
	{
		if (socket.receive(packet) == sf::Socket::Done)
			handleReceivedData(packet);
	}
}

void ConnectionHandler::handleReceivedData(sf::Packet& packet)
{
	string message;
	if (packet >> message);
		//std::cout << std::endl << std::endl << "Receieved data: \n" << message;
}

bool ConnectionHandler::sendData(string& message)
{
	sf::Packet packet;
	if (packet << message)
	{
		if(socket.send(packet) == sf::TcpSocket::Done)
			return true;
	}
	return false;
}