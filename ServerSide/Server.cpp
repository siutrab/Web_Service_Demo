#include "pch.h"
#include "Server.h"


	Server::Server(const unsigned int port)
		:	port(port),
			requestsQueue(),
			queryQueue(),
			resultingQueryQueue(),
			responseQueue(),
			sqlResultQueue(),
			errorHandler(&responseQueue),
			translatorXml(&queryQueue, &resultingQueryQueue, &requestsQueue, &responseQueue, &sqlResultQueue, &errorHandler),
			databaseHandler(&queryQueue, &resultingQueryQueue, &responseQueue, &sqlResultQueue, &errorHandler),
			responseHandler(&responseQueue, &errorHandler),
			router(port)
	{
		Client::setRequestQueuePtr(&requestsQueue);
		Client::setErrorHandlerPtr(&errorHandler);
	}


	Server::~Server()
	{	}


	void Server::start()
	{
		/*bool connectedToDatabase = false;
		do
		{*/
			//connectedToDatabase = databaseHandler.connectDatabase();
			//if (connectedToDatabase)
			if(databaseHandler.connectDatabase())
			{
				responseHandler.start();
				translatorXml.start();
				databaseHandler.start();
				router.start();
			}	
		//} while (connectedToDatabase == false);

	}

	void Server::stop()
	{
		responseHandler.stop();
		translatorXml.stop();

		router.stop();
		databaseHandler.stop();	
	}
