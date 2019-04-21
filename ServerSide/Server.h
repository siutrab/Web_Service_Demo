#pragma once
#include <thread>
#include "Router.h"
#include "RequestHandler.h"
#include "ResponseHandler.h"
#include "Client.h"
#include "RequestsQueue.h"
#include "QueryQueue.h"
#include "DatabaseHandler.h"

class DatabaseHandler;
class RequestHandler;
class ResponseHandler;
class RequestsQueue;
class QueryQueue;
class Router;
class Client;


using std::thread;

	class Server
	{
			const unsigned int port;
			Router* router;						// Receives and sednds prepared data from users
			RequestHandler* requestHandler;		// Handles users requests, encryption etc.
			ResponseHandler* responseHandler;	// Handles the responses, database querys etc.
			DatabaseHandler* databaseHandler;

		// Queues
			RequestsQueue* requestsQueue;
			QueryQueue* queryQueue;

		// server threads
			//thread routerThread;
			//thread requestQueueThread;

	public:
		Server(const unsigned int port);
		~Server();
		void start();	// main loop!!!
		void stop();
		RequestsQueue* getRequestsQueuePtr() const;
		
	};
