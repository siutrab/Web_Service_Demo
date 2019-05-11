#include "pch.h"
#include "Listener.h"

#include "Router.h"

Listener::Listener(Router* router)
	:	selector(router->getSelector()),
		clientsList(router->getClientsList())
{
	tcpListener.setBlocking(false);
	tcpListener.listen(router->getPort());
	selector->add(tcpListener);
}


Listener::~Listener()
{	}

void Listener::listen()
{
	// If there is new client on listeners socket
	if (selector->isReady(tcpListener))
	{
		Client* client = clientsList->addClient();
		TcpSocket* socket = client->getSocket();
		if (tcpListener.accept(*(socket)) == TcpSocket::Done)
		{
			selector->add(*socket);
		}
		// if connection is invalid the client is automaticall removed
		else clientsList->removeClient(client->getIndex());	
	}
}