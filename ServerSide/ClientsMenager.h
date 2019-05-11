#pragma once
#include "RequestQueue.h"
#include "SFML/Network.hpp"
#include <map>


using std::map;
using sf::SocketSelector;


class Router;

	class ClientsMenager
	{
		typedef std::pair<unsigned int, shared_ptr<Client>> mapPair;

			unsigned int numberOfClients;
			unsigned int clientUniqueNumber = 0;
			map <const unsigned int, shared_ptr<Client>> clientsMap;	// owner
			SocketSelector* const selector;
	public:
		ClientsMenager(Router* router);
		~ClientsMenager();
		void removeClient();
		Client* addClient();	// Creates a client and returns reference to it 
		void removeClient(const unsigned int index);
		void listen();
	};

