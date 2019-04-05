#include "pch.h"
#include "Listener.h"


//Listener::Listener(unsigned int port, sf::SocketSelector& selector, ConnectedClientsList& clientsList)
//	:	selector(selector),
//		clientsList(clientsList)
//{
//	listener.listen(port);
//	selector.add(listener);
//}

Listener::Listener(Router& router)
	:	selector(router.getSelector())
		//clientsList(router.getClientsList())
{
	clientsList = router.getClientsList();
	listener.listen(router.getPort());
	selector->add(listener);
}


Listener::~Listener()
{
}

void Listener::listen()
{
	// If there is new client on listeners socket
	if (selector->isReady(listener))
	{
		//sf::TcpSocket* socket = new sf::TcpSocket();
		Client* client = clientsList->addClient();
		sf::TcpSocket* socket = client->getSocket();
		if (listener.accept(*(socket)) == sf::TcpSocket::Done)
		{
			selector->add(*socket);
		}
		// if connection is invalid the client is automaticall removed
		else clientsList->deleteClient(client->getIndex());	
	}
}
