#include "pch.h"
#include "Server.h"

Server* Server::serverPointer;

	Server::Server(unsigned int port)
		:	requestsQueue(new RequestsQueue()),
			router(new Router(port)),
			requestHandler()
	{
		Server::setServerPointer(this);
		router->start();
	}

	Server::~Server()
	{
	}

	void Server::start()
	{

	}

	void Server::stop()
	{

	}

	void Server::setServerPointer(Server* pointer) { Server::serverPointer = pointer; }
	Server* Server::getServerPointer() { return Server::serverPointer; }