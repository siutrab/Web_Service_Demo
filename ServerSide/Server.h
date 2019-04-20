#pragma once
#include <thread>
#include "Router.h"
#include "RequestHandler.h"
#include "ResponseHandler.h"
#include "RequestsQueue.h"
#include "Client.h"

class RequestHandler;
class ResponseHandler;
class RequestsQueue;
class Router;
class Client;

using std::thread;

	class Server
	{
			const unsigned int port;
			Router* router;						// Receives and sednds prepared data from users
			RequestsQueue* requestsQueue;
			RequestHandler* requestHandler;		// Handles users requests, encryption etc.
			ResponseHandler* responseHandler;	// Handles the responses, database querys etc.
			
		// server threads
			thread routerThread;
			thread requestQueueThread;

	public:
		Server(const unsigned int port);
		~Server();
		void start();	// main loop!!!
		void stop();
		RequestsQueue* getRequestsQueuePtr() const;
		
	};
