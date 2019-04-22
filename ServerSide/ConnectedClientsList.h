#pragma once
#include "SFML/Network.hpp"
#include <map>
#include "Client.h"
#include "Router.h"
#include "RequestsQueue.h"

using std::map;
using sf::SocketSelector;

class Client;
class Router;

	class ConnectedClientsList
	{
		typedef std::pair<unsigned int, Client*> mapPair;

			unsigned int numberOfClients;
			unsigned int clientUniqueNumber = 0;
			map <unsigned int, Client*> clientsMap;	// owner
			SocketSelector* const selector;
	public:
		ConnectedClientsList(Router& router);
		~ConnectedClientsList();

		Client* addClient();	// Creates a client and returns reference to it 
		void deleteClient(const unsigned int index);
		void listen();
	};

