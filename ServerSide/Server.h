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
			// Queues are buffers between threads
			Queue requestsQueue;				
			Queue queryQueue;
			Queue resultingQueryQueue;
			Queue responseQueue;
			Queue sqlResultQueue;

			// Each of the below classes runs on separated thread
			ErrorHandler errorHandler;			// Collects errors in whole application and sends back error messages. Leads error log as well
			Router router;						// Receives and sednds prepared data from users
			TranslatorXml translatorXml;		// Translates XML to c++ and vice versa. Contains DataBase map
			DatabaseHandler databaseHandler;	// Handles two types of queries: resulting and nonresulting and executes them
			ResponseHandler responseHandler;	// Sends responses to the clients

		const unsigned int port;

	public:
		Server(const unsigned int port);
		~Server();
		void start();	// main loop of the thread
		void stop();	// joining the thread
	};
