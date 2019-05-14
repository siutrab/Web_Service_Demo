#include "pch.h"
#include "ConnectionHandler.h"
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
	bool running = true;
	ConnectionHandler connectionHandler(54000);
	
	if (connectionHandler.start())
	{
		while (running)
		{

		}
	}



	send(
		"																\
		<?xml version=\"1.0\"?>											\
		<soap:Envelope>													\
			<soap:Body>													\
				<request id = \"123456\" />								\
				<table name = \"materials\"/>							\
				<method name = \"create\">								\
					<name> FRONTROCK </name>							\
					<lambda> 0.034 </lambda>							\
					<widths>											\
						<width> 8 </width>								\
						<width> 10 </width>								\
						<width> 12 </width>								\
						<width> 14 </width>								\
						<width> 16 </width>								\
					</widths>											\
					<price> 127 </price>								\
					<type> wool </type>									\
					<producer> ROCKWOOL </producer>						\
					<link> www.rockwool.pl </link>						\
				</method>												\
			</soap:Body>												\
		</soap:Envelope>");
}

