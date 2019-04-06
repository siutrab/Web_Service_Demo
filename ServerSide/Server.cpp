#include "pch.h"
#include "Server.h"

	Server::Server(unsigned int port)
		:	router(&(Router(port))),
			requestsQueue(&(RequestsQueue()))
	{
		Client::setRequestQueuePointer(requestsQueue);
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
