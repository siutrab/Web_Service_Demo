#pragma once
#include "pugixml.hpp"
#include "RequestTranslatorXML.h"
#include "Server.h"
#include <thread>

class Server;
class RequestTranslatorXML;

class RequestHandler
{
	thread REQUEST_HANDLER_THREAD;
	bool running = false;
	RequestTranslatorXML* const translator;
	Server* const server;
public:
	RequestHandler(Server* const server);
	~RequestHandler();
	void start();
	void stop();
};

