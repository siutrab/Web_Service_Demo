#include "pch.h"
#include "Router.h"

Router::Router(unsigned int port)
	:	port(port),
		selector(),
		listener(new Listener(*this)),
		clientsList(new ConnectedClientsList(*this))
{
		ROUTER_THREAD = thread(&Router::start, this);
}

Router::~Router()
{
	stop();

	delete clientsList;
	delete listener;
}

void Router::start() 
{
	running = true; 
	while (running)
	{
		// Selector waits for data at any socket
		if (selector.wait())
		{
			this->listener->listen();
			clientsList->listen();
		}
	}
}
void Router::stop() 
{
	ROUTER_THREAD.join();
	running = false; 
}

unsigned int Router::getPort() { return port; }
SocketSelector* Router::getSelector() { return &selector; }
ConnectedClientsList* Router::getClientsList() { return clientsList; }