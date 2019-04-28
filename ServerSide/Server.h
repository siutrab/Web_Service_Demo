#pragma once

#include "Router.h"

#include "DatabaseHandler.h"


	class Server
	{
			const unsigned int port;
			// Each of the below classes runs on separated thread
			Router router;						// Receives and sednds prepared data from users
			TranslatorXml translatorXml;
			//RequestHandler requestHandler;		// Handles users requests, encryption etc.
			DatabaseHandler databaseHandler;	// Connection to database
			//ResponseHandler responseHandler;	// Handles the responses, database querys etc.

		// Queues
			RequestQueue requestsQueue;
			//NonResultQueryQueue nonResultQuery;

	public:
		Server(const unsigned int port);
		~Server();
		void start();	// main loop!!!
		void stop();
		//RequestQueue* getRequestsQueuePtr();
		
	};
