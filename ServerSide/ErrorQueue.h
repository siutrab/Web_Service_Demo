#pragma once
#include "ErrorResponse.h"
#include "QueueItem.h"
#include "Queue.h"
#include "Client.h"
#include <memory>

using std::auto_ptr;

class Client;
class Request;

class ErrorQueue
	: public Queue
{
	//string& unpackException(ExceptionInterface exception);
public:
	ErrorQueue();
	~ErrorQueue();
	void addItem(unique_ptr<QueueItem> queueItem, ExceptionInterface& exception);
	//void addItem(QueueItem& item) override;
};
