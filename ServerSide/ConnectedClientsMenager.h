#pragma once
#include "RequestQueue.h"
#include "SFML/Network.hpp"
#include <map>


using std::map;
using sf::SocketSelector;


class Router;

	class ConnectedClientsMenager
	{
		typedef std::pair<unsigned int, shared_ptr<Client>> mapPair;

			unsigned int numberOfClients;
			unsigned int clientUniqueNumber = 0;
			map <const unsigned int, shared_ptr<Client>> clientsMap;	// owner
			SocketSelector* const selector;
	public:
		ConnectedClientsMenager(Router* router);
		~ConnectedClientsMenager();

		Client* addClient();	// Creates a client and returns reference to it 
		void deleteClient(const unsigned int index);
		void listen();
	};

