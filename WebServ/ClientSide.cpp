#include "pch.h"
#include <iostream>
#include "SFML/Network.hpp"

int main()
{
	sf::TcpSocket* socket = new sf::TcpSocket();
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	unsigned int port = 54000;
	sf::Packet* packet = new sf::Packet();
	*packet << "aohgeoshsigjogiejsg";

	if (socket->connect(ip, port) == sf::Socket::Done)
		socket->send(*packet);
	
	delete packet;
}
