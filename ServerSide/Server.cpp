#include "pch.h"
#include "Server.h"


	Server::Server(const unsigned int port)
		:	port(port),
			requestsQueue(),
			errorQueue(),
			queryQueue(),
			responseQueue(),
			translatorXml(&queryQueue, &requestsQueue, &errorQueue),
			databaseHandler(&queryQueue, &responseQueue, &errorQueue),
			responseHandler(&responseQueue),
			router(port)
	{

		Client::setRequestQueuePtr(&requestsQueue);
		Client::setErrorQueuePtr(&errorQueue);
	
		responseHandler.start();
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
