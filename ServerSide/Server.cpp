#include "pch.h"
#include "Server.h"


	Server::Server(const unsigned int port)
		:	port(port),
			requestsQueue(),
			errorQueue(),
			queryQueue(),
			resultingQueryQueue(),
			responseQueue(),
			sqlResultQueue(),
			translatorXml(&queryQueue, &resultingQueryQueue, &requestsQueue, &responseQueue, &sqlResultQueue, &errorQueue),
			//responseTranslator(&errorQueue, &responseQueue, &entityQueue),
			databaseHandler(&queryQueue, &resultingQueryQueue, &responseQueue, &sqlResultQueue, &errorQueue),
			responseHandler(&responseQueue, &errorQueue),
			router(port)
	{
		Client::setRequestQueuePtr(&requestsQueue);
		Client::setErrorQueuePtr(&errorQueue);
	
		
	}


	Server::~Server()
	{	}

	void Server::start()
	{
		bool connectedToDatabase = false;
		do
		{
			connectedToDatabase = databaseHandler.connectDatabase();
			if (connectedToDatabase)
			{
				responseHandler.start();
				translatorXml.start();
				databaseHandler.start();
				router.start();
			}	
		} while (connectedToDatabase == false);

	}

	void Server::stop()
	{
		responseHandler.stop();
		translatorXml.stop();
		databaseHandler.stop();
		router.stop();

		databaseHandler.stop();		// Has to be called because database connection has to be closed
	}
