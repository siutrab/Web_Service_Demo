#include "pch.h"
#include <iostream>
#include "SFML/Network.hpp"
#include <thread>

void send()
{
	sf::TcpSocket socket;
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	unsigned int port = 54000;
	sf::Packet* packet = new sf::Packet();

	for (int i = 0; i < 30; i++)
	{
		if (*packet << "aohgeoshsigjogiejsg")
		{

				if (socket.connect(ip, port) == sf::Socket::Done)
					socket.send(*packet);
		}
	}

	delete packet;
}

int main()
{
	
		send();
	
}
