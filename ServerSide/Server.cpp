#include "pch.h"
#include "Server.h"

	Server::Server(const unsigned int port)
		:	port(port),
			requestsQueue(new RequestsQueue()),
			router(new Router(port)),
			requestHandler()
	{
		router->start();
	}

	Server::~Server()
	{	}

	void Server::start()
	{	}

	void Server::stop()
	{	}

	RequestsQueue* Server::getRequestsQueuePtr() const { return requestsQueue; }
