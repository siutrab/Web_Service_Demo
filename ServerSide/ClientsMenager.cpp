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


	Client* ClientsMenager::addClient()
	{
		shared_ptr<Client> client = std::make_shared<Client>(clientUniqueNumber);
		unsigned int clientIndex = client->getIndex();
		clientsMap.insert(mapPair (clientIndex, client));
		clientUniqueNumber++;
		return &*client;
	}


	void ClientsMenager::removeClient(const unsigned int index)
	{
		shared_ptr<Client> client = clientsMap.at(index);
		TcpSocket* socket = client->getSocket();
		selector->remove(*socket);
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