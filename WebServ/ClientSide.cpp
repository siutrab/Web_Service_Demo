#include "pch.h"
#include "ConnectionHandler.h"
#include "CreateMethodDocument.h"
#include "SFML/Network.hpp"
#include <iostream>
#include <thread>

//void send(std::string comunicate)
//{
//	sf::TcpSocket socket;
//	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
//	unsigned int port = 54000;
//	sf::Packet packet;
//
//	if (packet << comunicate)
//	{
//		if (socket.connect(ip, port) == sf::Socket::Done)
//			socket.send(packet);
//	}
//}



int main()
{
	bool run = true;
	ConnectionHandler connectionHandler(54000);
	CreateMethodDocument createDocument;

	

	
	if (connectionHandler.start())
	{
		while (run)
		{
			createDocument.collectData();
			string* xmlFile = createDocument.generateXml();
			connectionHandler.sendData(*xmlFile);
		}
	}




}

