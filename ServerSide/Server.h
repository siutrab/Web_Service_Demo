#pragma once
#include "Router.h"
#include "ResponseHandler.h"
#include "DatabaseHandler.h"
#include "Queue.h"
#include "ErrorHandler.h"
#include "TranslatorXml.h"
#include "ResponseTranslatorXml.h"

	class Server
	{
			// Queues
			Queue requestsQueue;				
			Queue queryQueue;
			Queue resultingQueryQueue;
			Queue responseQueue;
			Queue sqlResultQueue;

			// Each of the below classes runs on separated thread
			ErrorHandler errorHandler;			
			Router router;						// Receives and sednds prepared data from users
			TranslatorXml translatorXml;
			DatabaseHandler databaseHandler;	// Connection to database
			ResponseHandler responseHandler;

		const unsigned int port;

	public:
		Server(const unsigned int port);
		~Server();
		void start();	// main loop!!!
		void stop();
	};
