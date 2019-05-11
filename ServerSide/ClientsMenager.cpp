#include "pch.h"
#include "Router.h"
#include "ClientsMenager.h"
	ClientsMenager::ClientsMenager(Router* router)
		:	selector(router->getSelector())
	{
		Client::setClientsMenagerPtr(this);
	}

	ClientsMenager::~ClientsMenager()
	{	}

// methods
	Client* ClientsMenager::addClient()
	{
		Client* client = new Client(clientUniqueNumber);
		unsigned int clientIndex = client->getIndex();
		clientsMap.insert(mapPair (clientIndex, client));
		clientUniqueNumber++;
		return client;
	}

	void ClientsMenager::removeClient(const unsigned int index)
	{
		clientsMap.erase(index);
	}

	void ClientsMenager::listen()
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