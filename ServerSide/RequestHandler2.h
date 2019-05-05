#pragma once
#include "pugixml.hpp"
#include "TranslatorXML.h"
#include <thread>

using std::thread;
using std::unique_ptr;

class RequestHandler;

class RequestHandler2
{
	thread REQUEST_HANDLER_THREAD;
	bool running = false;
	const unique_ptr<RequestHandler> translator;
	//const unique_ptr<DatabaseHandler> databaseHandler;

public:
	RequestHandler2();
	~RequestHandler2();
	void start();
	void stop();
};

