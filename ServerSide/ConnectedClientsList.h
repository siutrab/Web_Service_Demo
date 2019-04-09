#pragma once
#include "SFML/Network.hpp"
#include <vector>
#include <map>
#include "Client.h"
#include "Router.h"
#include "RequestsQueue.h"

class Client;
class Router;

	class ConnectedClientsList
	{
			unsigned int numberOfClients;
			unsigned int clientUniqueNumber = 0;
			std::map <unsigned int, Client*> clientsMap;	// owner
			sf::SocketSelector* const selector;
	public:
		ConnectedClientsList(Router& router);
		~ConnectedClientsList();

		Client* addClient();	// Creates a client and returns reference to it 
		void deleteClient(const unsigned int index);
		void listen();
	};

