#include "pch.h"
#include "Router.h"
#include "ConnectedClientsMenager.h"
	ConnectedClientsMenager::ConnectedClientsMenager(Router* router)
		:	selector(router->getSelector())
	{	}

	ConnectedClientsMenager::~ConnectedClientsMenager()
	{	}

// methods
	Client* ConnectedClientsMenager::addClient()
	{
		Client* client = new Client(clientUniqueNumber);
		unsigned int clientIndex = client->getIndex();
		clientsMap.insert(mapPair (clientIndex, client));
		clientUniqueNumber++;
		return client;
	}

	void ConnectedClientsMenager::deleteClient(const unsigned int index)
	{
		clientsMap.erase(index);
	}

	void ConnectedClientsMenager::listen()
	{
		for (auto i = clientsMap.begin(); i != clientsMap.end(); ++i)
		{
			mapPair pair = *i;
			shared_ptr<Client> client = pair.second;
			TcpSocket* socket = client->getSocket();

			if (selector->isReady(*socket))
				client->receivePacket();
		}
	}