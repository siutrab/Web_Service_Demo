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
{
	stop();
}

void Router::run() 
{
	
	while (running)
	{
		// Selector waits for data at any socket
		if (selector.wait())
		{
			listener.listen();
			clientsList.listen();
		}
	}
}
void Router::stop() 
{
	ROUTER_THREAD.join();
	running = false; 
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