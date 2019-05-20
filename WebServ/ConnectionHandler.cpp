#include "pch.h"
#include "ConnectionHandler.h"

unsigned int ConnectionHandler::requestNumber = 0;

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

bool ConnectionHandler::stop()
{
	running = false;
	if (CONNECTION_HANDLER_THREAD.joinable())
		CONNECTION_HANDLER_THREAD.join();
	socket.disconnect();

	return true;
}

void ConnectionHandler::handleReceivedData(sf::Packet& packet)
{
	string message;
	if (packet >> message)
	{
		responeBuffer.push_back(message);
	}
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

unsigned int ConnectionHandler::getRequestNumber()
{
	requestNumber++;
	return requestNumber;
}

bool ConnectionHandler::printResponseMessages()
{
	size_t responseCount = responeBuffer.size();
	if (responseCount > 0)
	{
		for (size_t i = 0; i < responseCount; i++)
		{
			cout << responeBuffer[i] << endl << endl;
			
		}
		responeBuffer.resize(0);
		return true;
	}

	return false;
}

bool ConnectionHandler::responseBufferIsEmpty()
{
	return responeBuffer.empty();
}