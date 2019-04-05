#include "pch.h"
#include "Router.h"

Router::Router(unsigned int port)
	:	port(port),
		selector(),
		listener(port, selector)
{
	start();
}


Router::~Router()
{
	
}

void Router::start() 
{
	running = true; 
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
void Router::stop() { running = false; }
