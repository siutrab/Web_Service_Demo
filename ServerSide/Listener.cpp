#include "pch.h"
#include "Listener.h"

Listener* Listener::listenerPointer = nullptr;

Listener::Listener(Router& router)
	:	selector(router.getSelector())
{
	Listener::setListenerPointer(this);
	tcpListener.setBlocking(false);
	clientsList = router.getClientsList();
	tcpListener.listen(router.getPort());
	selector->add(tcpListener);
}


Listener::~Listener()
{
}

void Listener::listen()
{
	// If there is new client on listeners socket
	if (selector->isReady(tcpListener))
	{
		//sf::TcpSocket* socket = new sf::TcpSocket();
		Client* client = clientsList->addClient();
		sf::TcpSocket* socket = client->getSocket();
		if (tcpListener.accept(*(socket)) == sf::TcpSocket::Done)
		{
			selector->add(*socket);
		}
		// if connection is invalid the client is automaticall removed
		else clientsList->deleteClient(client->getIndex());	
	}
}

void Listener::setListenerPointer(Listener* pointer) { Listener::listenerPointer = pointer; }
Listener* Listener::getListenrPointer() { return Listener::listenerPointer; }