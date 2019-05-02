#pragma once
#include "ErrorResponse.h"
#include "QueueItem.h"
#include "Queue.h"
#include "Client.h"

class Client;
class Request;

class ErrorQueue
	: public Queue
{
	//string& unpackException(ExceptionInterface exception);
public:
	ErrorQueue();
	~ErrorQueue();
	void addItem(QueueItem& queueItem, ExceptionInterface& exception);
	//void addItem(QueueItem& item) override;
};

