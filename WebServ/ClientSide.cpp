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
	send(
		"<?xml version=\"1.0\"?>											\
																			\
		<soap:Envelope														\
		xmlns : soap = \"http://www.w3.org/2003/05/soap-envelope/\"			\
		soap : encodingStyle = \"http://www.w3.org/2003/05/soap-encoding\">	\
			<soap:Body>														\
				<table name = \"materials\">								\
					<method name = \"create\">								\
						<name> FRONTROCK </name>							\
						<lambda> 0.034 </lambda>							\
						<widths number = \"5\">								\
							<width> 8 </width>								\
							<width> 10 </width>								\
							<width> 12 </width>								\
							<width> 14 </width>								\
							<width> 16 </width>								\
						</widths>											\
						<price> 0.034 </price>								\
						<type> wool </type>									\
						<producer> ROCKWOOL </producer>						\
						<link> www.rockwool.pl </link>						\
					</method>												\
				</table>													\
			</soap:Body>													\
		< / soap:Envelope>");
}