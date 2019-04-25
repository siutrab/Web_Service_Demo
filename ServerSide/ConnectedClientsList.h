#ifndef CONNECTED_CLIENTS_H
#define CONNECTED_CLIENTS_H

#pragma once
#include "Client.h"
#include "Router.h"
#include "SFML/Network.hpp"
#include <map>



using std::map;
using sf::SocketSelector;


class Router;

	class ConnectedClientsList
	{
		typedef std::pair<unsigned int, Client*> mapPair;

			unsigned int numberOfClients;
			unsigned int clientUniqueNumber = 0;
			map <unsigned int, Client*> clientsMap;	// owner
			SocketSelector* const selector;
	public:
		ConnectedClientsList(Router* router);
		~ConnectedClientsList();

		Client* addClient();	// Creates a client and returns reference to it 
		void deleteClient(const unsigned int index);
		void listen();
	};

#endif // !CONNECTED_CLIENTS_H
