#include "pch.h"
#include "Server.h"


	Server::Server(const unsigned int port)
		:	port(port),
			requestsQueue(new RequestsQueue()),
			queryQueue(new QueryQueue())
			
	{
	// WARNING!!! don't move these parts to initialization list, because request queues have to be initialized first
	// because they initialize static members of classes under this comments
		router = new Router(port);
		requestHandler = new RequestHandler(this);
		databaseHandler = new DatabaseHandler(this);
	// threads		
		//routerThread = thread(&(Router::start), router);
		//requestQueueThread = thread(&(RequestHandler::start), requestHandler);


	}


	Server::~Server()
	{	}

	void Server::start()
	{


	}

	void Server::stop()
	{	}

	RequestsQueue* Server::getRequestsQueuePtr() const { return requestsQueue; }
