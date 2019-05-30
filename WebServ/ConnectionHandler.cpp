#include "pch.h"
#include "ConnectionHandler.h"

unsigned int ConnectionHandler::requestNumber = 0;

string ConnectionHandler::disconnectMessage = "<?xml version=\"1.0\"?><soap:Envelope><soap:Body><disconnect/></soap:Body></soap:Envelope>";

ConnectionHandler::ConnectionHandler(unsigned int port, sf::IpAddress ip)
	:	socket(),
		ipAddress()
{
	this->port = port;
	ipAddress = ip;	

	connect();
}


ConnectionHandler::~ConnectionHandler()
{
	disconnect();
}


void ConnectionHandler::connect()
{
	cout << "Wait for connection..." << endl;

	bool connected = false;
	do
	{
		connected = (socket.connect(ipAddress, port) == sf::Socket::Done);
	} while (!connected);

	cout << "Connected" << endl << endl;
}

void ConnectionHandler::disconnect()
{
	sendData(disconnectMessage);
	socket.disconnect();
}


void ConnectionHandler::waitForResponse(MethodInterface* method)
{
	sf::Packet packet;

	while (true)
	{
		if (socket.receive(packet) == sf::Socket::Done)
		{
			handleReceivedData(packet, method);
			return;
		}
	}
}


void ConnectionHandler::handleReceivedData(sf::Packet& packet, MethodInterface* method)
{
	string message;

	if (packet >> message)
		method->printResponse(message);
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
