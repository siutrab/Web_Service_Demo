#include "pch.h"
#include "Server.h"


	Server::Server(const unsigned int port)
		:	port(port),
			requestsQueue(),
			nonResultQuery(),
			router(port),
			requestHandler(),
			databaseHandler()
	{
	// WARNING!!! don't move these parts to initialization list. 
	//	Request queues have to be initialized first
	// because they initialize static members of classes under this comments
	// WARNING!!! each of below runs on different threads
		requestHandler.start();
		databaseHandler.start();
		router.start();
	}


	Server::~Server()
	{	}

	void Server::start()
	{	}

	void Server::stop()
	{	}

	RequestsQueue* Server::getRequestsQueuePtr() { return &requestsQueue; }
