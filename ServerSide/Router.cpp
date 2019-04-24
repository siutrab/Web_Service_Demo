#include "pch.h"
#include "Router.h"

Router::Router(unsigned int port)
	:	port(port),
		selector(),
		listener(new Listener(*this)),
		clientsList(new ConnectedClientsList(*this))
{

}

void Router::start()
{
	ROUTER_THREAD = thread(&Router::run, this);
}

Router::~Router()
{
	stop();

}

void Router::run() 
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
ConnectedClientsList* Router::getClientsList() { return &*clientsList; }