#pragma once
#include "ErrorResponse.h"
#include "TranslatorFromXml.h"
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
public:
	ErrorQueue();
	~ErrorQueue();
	void addItem(unique_ptr<QueueItem> queueItem, ExceptionInterface& exception);
};

