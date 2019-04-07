#pragma once
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

	class Server
	{
			Router* router;		// Receives and sednds prepared data from users
			RequestsQueue* requestsQueue;
			RequestHandler* requestHandler;	// Handles users requests, encryption etc.
			ResponseHandler* responseHandler;	// Handles the responses, database querys etc.
	public:
			static const int port;
		Server(unsigned int port);
		~Server();
		void start();	// main loop!!!
		void stop();
	};
