#include "pch.h"
#include "Server.h"


	Server::Server(const unsigned int port)
		:	port(port),
			requestsQueue(new RequestsQueue()),
			queryQueue(new NonResultQueryQueue()),
			router(port)
	{
	// WARNING!!! don't move these parts to initialization list. 
	//	Request queues have to be initialized first
	// because they initialize static members of classes under this comments
	// WARNING!!! each of below runs on different threads
		//router = new Router(port);
		//router = Router(port);
		requestHandler = new RequestHandler();
		databaseHandler = new DatabaseHandler();
	}


	Server::~Server()
	{	}

	void Server::start()
	{	}

	void Server::stop()
	{	}

	//RequestsQueue* Server::getRequestsQueuePtr() const { return requestsQueue; }
