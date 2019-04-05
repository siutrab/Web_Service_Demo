#pragma once
#include "Router.h"
#include "RequestHandler.h"
#include "ResponseHandler.h"
class RequestHandler;
class ResponseHandler;
class Server
{
	Router router;		// Receives and sednds prepared data from users
	RequestHandler requestHandler;	// Handles users requests, encryption etc.
	ResponseHandler responseHandler;	// Handles the responses, database querys etc.
public:
	Server();
	~Server();
	void start();	// main loop!!!
	void stop();
};

