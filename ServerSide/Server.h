#ifndef SERVER_H
#define SERVER_H
#pragma once
#include "RequestHandler.h"
#include "ResponseHandler.h"
#include "RequestsQueue.h"
#include "NonResultQueryQueue.h"
#include "DatabaseHandler.h"
#include "Router.h"


	class Server
	{
			const unsigned int port;
			// Each of the below classes runs on separated thread
			Router router;						// Receives and sednds prepared data from users
			RequestHandler requestHandler;		// Handles users requests, encryption etc.
			DatabaseHandler databaseHandler;	// Connection to database
			ResponseHandler responseHandler;	// Handles the responses, database querys etc.

		// Queues
			RequestQueue requestsQueue;
			NonResultQueryQueue nonResultQuery;

	public:
		Server(const unsigned int port);
		~Server();
		void start();	// main loop!!!
		void stop();
		RequestQueue* getRequestsQueuePtr();
		
	};

#endif // !SERVER_H
