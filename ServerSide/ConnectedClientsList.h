#pragma once
#include "SFML/Network.hpp"
#include <vector>
#include <map>
#include "Client.h"
#include "Router.h"

class Client;
class Router;

class ConnectedClientsList
{
	//std::map<Client*, unsigned int>clientsMap;
	std::vector<Client*> clientsList;
	sf::SocketSelector* selector;
public:
	//ConnectedClientsList(sf::SocketSelector& selector);
	ConnectedClientsList(Router& router);
	~ConnectedClientsList();
	Client* addClient();	// Creates a client and returns reference to it 
	void deleteClient(Client& client);
	void listen();
};

