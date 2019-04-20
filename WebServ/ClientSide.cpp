#include "pch.h"
#include <iostream>
#include "SFML/Network.hpp"
//#include <thread>

void send(std::string comunicate)
{
	sf::TcpSocket socket;
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	unsigned int port = 54000;
	sf::Packet packet;

	/*for (int i = 0; i < 30; i++)
	{
*/
	if (packet << comunicate)
	{
		if (socket.connect(ip, port) == sf::Socket::Done)
			socket.send(packet);
	}
	//}
}

int main()
{
	/*std::thread thread1(send,"thread1");
	std::thread thread2(send, "THREAD2");
	std::thread thread3(send, "th3");*/

	//thread1.join();
	//thread2.join();
	//thread3.join();
	send("<?xml version=\"1.0\" encoding=\"UTF - 8\"?><note><blah> oiafoesg </blah></note>");
}