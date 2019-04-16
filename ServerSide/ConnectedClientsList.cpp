#include "pch.h"
#include "ConnectedClientsList.h"

	ConnectedClientsList::ConnectedClientsList(Router& router)
		:	selector(router.getSelector())
	{	}

	ConnectedClientsList::~ConnectedClientsList()
	{
		for (auto i = clientsMap.begin(); i != clientsMap.end(); ++i)
		{
			mapPair pair = *i;
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
		clientsMap.insert(mapPair (clientIndex, client));
		clientUniqueNumber++;
		return client;
	}

	void ConnectedClientsList::deleteClient(const unsigned int index)
	{
		Client* client = clientsMap[index];
		delete client;
		client = nullptr;
		clientsMap.erase(index);
	}

	void ConnectedClientsList::listen()
	{
		for (auto i = clientsMap.begin(); i != clientsMap.end(); ++i)
		{
			mapPair pair = *i;
			Client* client = pair.second;
			TcpSocket* socket = client->getSocket();

			if (selector->isReady(*socket))
				client->receivePacket();
		}
	}