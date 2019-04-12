#include "pch.h"
#include "Server.h"


	Server::Server(const unsigned int port)
		:	port(port),
			requestsQueue(new RequestsQueue()),
			router(new Router(port)),
			requestHandler(new RequestHandler(this)),
		// threads
			routerThread(std::thread(&(Router::start), router)),
			requestQueueThread(std::thread(&(RequestHandler::start), requestHandler))
	{	}

	Server::~Server()
	{	}

	void Server::start()
	{	}

	void Server::stop()
	{	}

	RequestsQueue* Server::getRequestsQueuePtr() const { return requestsQueue; }
