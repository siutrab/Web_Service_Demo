#include "pch.h"
#include "ConnectedClientsList.h"


//ConnectedClientsList::ConnectedClientsList(sf::SocketSelector& selector)
//	:	selector(selector)
//{
//}

ConnectedClientsList::ConnectedClientsList(Router& router)
	:	selector(router.getSelector())
{

}

ConnectedClientsList::~ConnectedClientsList()
{
}

Client* ConnectedClientsList::addClient()
{
	Client* client = new Client();	// client index is the length of actual size of vector
	clientsList.push_back(client);
	return client;
}

void ConnectedClientsList::deleteClient(Client& client)
{
	unsigned int removeClientIndex = client.getIndex();
	unsigned int lastClientIndex = clientsList.size() - 1;

	// removeing client
	delete clientsList[removeClientIndex];
	clientsList[removeClientIndex] = nullptr;

	// if client istn't the las one, swap with the last
	if (removeClientIndex != (lastClientIndex))
	{
		Client* lastClientPointer = clientsList[lastClientIndex];
		clientsList[removeClientIndex] = lastClientPointer;			// swap		
		lastClientPointer->setIndex(removeClientIndex);				// setting new index to swapped Client

		clientsList[lastClientIndex] = nullptr;
	}
	// resized vector is the length of last client index (because indexes starts from 0)
	clientsList.resize(lastClientIndex);
}

void ConnectedClientsList::listen()
{
	for (size_t i = 0; i < clientsList.size(); i++)
	{
		Client* client = clientsList[i];
		sf::TcpSocket* socket = client->getSocket();

		if (selector->isReady(*socket))
		{
			client->receivePacket();
			//// receveing packet
			//sf::Packet packet;
			//if (socket->receive(packet) == sf::Socket::Done)
			//{
			//	client->receivePacket(packet);
			//}
		}
	}
}