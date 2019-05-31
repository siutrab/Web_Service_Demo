#pragma once
#include "ErrorMessage.h"
#include "ErrorTranslatorXml.h"
#include "ErrorLogger.h"

#include "Response.h"
#include "QueueItem.h"
#include "Queue.h"
#include "Client.h"
#include <memory>

using std::unique_ptr;

class Client;
class Request;

class ErrorHandler
{
	Queue* responseQueue;
	ErrorLogger errorLogger;
	ErrorTranslatorXml	errorTranslator;
public:
	ErrorHandler(Queue* responseQueue);
	~ErrorHandler();
	void createError(unique_ptr<QueueItem> queueItem, ExceptionInterface& exception);	// push error on an responseQueue, log error
};

