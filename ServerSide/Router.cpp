#include "pch.h"
#include "Router.h"	

Router::Router(unsigned int port)
	:	port(port),
		selector(),
		listener(this),
		clientsList(this),
		running(false)
{	}

void Router::start()
{
	running = true; 
	ROUTER_THREAD = thread(&Router::run, this);
}

Router::~Router()
{	}

void Router::run() 
{
	sf::Time waitingTime = sf::microseconds(10);
	while (running)
	{
		// Selector waits for data at any socket
		if (selector.wait(waitingTime))
		{
			listener.listen();
			clientsList.listen();
		}
	}
}


void Router::stop() 
{
	running = false;
	if (ROUTER_THREAD.joinable())
		ROUTER_THREAD.join();
}


unsigned int Router::getPort() 
{ 
	return port; 
}


SocketSelector* Router::getSelector() 
{ 
	return &selector; 
}


ClientsMenager* Router::getClientsList()
{ 
	return &clientsList;
}