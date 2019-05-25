#pragma once
#include "ErrorMessage.h"
#include "ErrorTranslatorXml.h"
#include "ErrorLogger.h"
#include "RequestTranslatorXml.h"
#include "QueueItem.h"
#include "Queue.h"
#include "Client.h"
#include <memory>

using std::unique_ptr;

class Client;
class Request;

class ErrorQueue
	: public Queue
{
	ErrorLogger errorLogger;
	ErrorTranslatorXml	errorTranslator;
public:
	ErrorQueue();
	~ErrorQueue();
	void addItem(unique_ptr<QueueItem> queueItem, ExceptionInterface& exception);
};

