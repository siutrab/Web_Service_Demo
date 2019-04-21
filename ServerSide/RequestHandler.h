#pragma once
#include "pugixml.hpp"
#include "RequestTranslatorXML.h"
#include <thread>

using std::thread;
using std::unique_ptr;

class RequestTranslatorXML;

class RequestHandler
{
	thread REQUEST_HANDLER_THREAD;
	bool running = false;
	const unique_ptr<RequestTranslatorXML> translator;
	unique_ptr<DatabaseHandler> databaseHandler;

public:
	RequestHandler();
	~RequestHandler();
	void start();
	void stop();
};

