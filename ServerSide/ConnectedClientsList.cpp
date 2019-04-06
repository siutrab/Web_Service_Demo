#include "pch.h"
#include "ConnectedClientsList.h"

	ConnectedClientsList::ConnectedClientsList(Router& router)
		:	selector(router.getSelector())
	{

	}

	ConnectedClientsList::~ConnectedClientsList()
	{
		for (std::map<unsigned int, Client*>::iterator i = clientsMap.begin(); i != clientsMap.end(); ++i)
		{
			std::pair<unsigned int, Client*> pair = *i;
			Client* client = pair.second;
			delete client;
			client = nullptr;
		}
	}

// methods
	Client* ConnectedClientsList::addClient()
	{
		Client* client = new Client(clientUniqueNumber);
		unsigned int clientIndex = client->getIndex();
		clientsMap.insert(std::pair<unsigned int, Client*> (clientIndex, client));
		clientUniqueNumber++;
		return client;
	}

	void ConnectedClientsList::deleteClient(unsigned int index)
	{
		Client* client = clientsMap[index];
		delete client;
		client = nullptr;
		clientsMap.erase(index);

	}

	void ConnectedClientsList::listen()
	{
		for (std::map<unsigned int, Client*>::iterator i = clientsMap.begin(); i != clientsMap.end(); ++i)
		{
			std::pair<unsigned int, Client*> pair = *i;
			Client* client = pair.second;
			sf::TcpSocket* socket = client->getSocket();

			if (selector->isReady(*socket))
			{
				client->receivePacket();
			}
		}
	}