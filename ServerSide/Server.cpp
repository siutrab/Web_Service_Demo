#include "pch.h"
#include "Server.h"


	Server::Server(const unsigned int port)
		:	port(port),
			requestsQueue(),
			translatorXml(),
			//nonResultQuery(),
			router(port),
			databaseHandler()
	{
	// WARNING!!! don't move these parts to initialization list. 
	// Request queue have to be initialized first
	// because they initialize static members of classes under this comments
	// WARNING!!! each of below runs on different threads
		translatorXml.start();
		databaseHandler.start();
		router.start();
	}


	Server::~Server()
	{	}

	void Server::start()
	{	}

	void Server::stop()
	{	}

	//RequestQueue* Server::getRequestsQueuePtr() { return &requestsQueue; }
