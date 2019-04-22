#pragma once
#include "Router.h"
#include "RequestHandler.h"
#include "ResponseHandler.h"
#include "Client.h"
#include "RequestsQueueXML.h"
#include "NonResultQueryQueue.h"
#include "DatabaseHandler.h"

class DatabaseHandler;
class RequestHandler;
class ResponseHandler;
class RequestsQueueXml;
class NonResultQueryQueue;
class Router;
class Client;



	class Server
	{
			const unsigned int port;

			// Each of the below classes runs on separated thread
			Router* router;						// Receives and sednds prepared data from users
			RequestHandler* requestHandler;		// Handles users requests, encryption etc.
			DatabaseHandler* databaseHandler;	// Connection to database
			ResponseHandler* responseHandler;	// Handles the responses, database querys etc.

		// Queues
			RequestsQueueXml* requestsQueue;
			NonResultQueryQueue* queryQueue;

	public:
		Server(const unsigned int port);
		~Server();
		void start();	// main loop!!!
		void stop();
		RequestsQueueXml* getRequestsQueuePtr() const;
		
	};
