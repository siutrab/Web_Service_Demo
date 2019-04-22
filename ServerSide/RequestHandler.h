#pragma once
#include "pugixml.hpp"
#include "TranslatorXML.h"
#include <thread>

using std::thread;
using std::unique_ptr;

class TranslatorXML;

class RequestHandler
{
	thread REQUEST_HANDLER_THREAD;
	bool running = false;
	const unique_ptr<TranslatorXML> translator;
	const unique_ptr<DatabaseHandler> databaseHandler;

public:
	RequestHandler();
	~RequestHandler();
	void start();
	void stop();
};

