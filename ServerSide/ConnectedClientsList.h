#pragma once
#include "SFML/Network.hpp"
#include <vector>
#include <map>
#include "Client.h"

class ConnectedClientsList
{
	//std::map<Client*, unsigned int>clientMap;
	std::vector<Client*> clientsList;
	sf::SocketSelector& selector;
public:
	ConnectedClientsList(sf::SocketSelector& selector);
	~ConnectedClientsList();
	Client* addClient();	// Creates a client and returns reference to it 
	void deleteClient(Client& client);
	void listen();
};

