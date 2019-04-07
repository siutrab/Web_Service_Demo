#include "pch.h"
#include "Server.h"

	Server::Server(unsigned int port)
		:	requestsQueue(new RequestsQueue()),
			router(new Router(port))	
	{
		Client::setRequestQueuePointer(requestsQueue);
		router->start();
	}

	Server::~Server()
	{
	}

	void Server::start()
	{

	}

	void Server::stop()
	{

	}
