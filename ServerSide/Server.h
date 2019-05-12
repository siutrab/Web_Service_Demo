#pragma once

#include "Router.h"
#include "ResponseHandler.h"
#include "DatabaseHandler.h"
#include "Queue.h"
#include "ErrorQueue.h"


	class Server
	{
		// Queues
			Queue requestsQueue;
			Queue queryQueue;
			Queue responseQueue;
			ErrorQueue errorQueue;

			const unsigned int port;
			// Each of the below classes runs on separated thread
			Router router;						// Receives and sednds prepared data from users
			TranslatorXml translatorXml;
			DatabaseHandler databaseHandler;	// Connection to database
			ResponseHandler responseHandler;
			//ResponseTranslator responseTranslator;



	public:
		Server(const unsigned int port);
		~Server();
		void start();	// main loop!!!
		void stop();
		
	};
