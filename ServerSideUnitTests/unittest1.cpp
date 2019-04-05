#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../ServerSide/Router.h"
#include "../ServerSide/ConnectedClientsList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
class Router;
class connectedClients
	: public ConnectedClientsList
{
public:
	Client* client = new Client();
	bool isEqual = false;
	sf::SocketSelector* selector;
	void assert()
	{
		std::cout << client;
		/*if (client == (int)client)
		{
			isEqual = true;
		}*/
	}
	connectedClients(Router& router) : selector(router.getSelector()) {}

};

namespace ServerSideUnitTests
{		
	TEST_CLASS(AddingClient)
	{
	public:
		
		TEST_METHOD(ClientPointer)
		{
			connectedClients connClients;
			connClients.assert();
			
		}

	};
}