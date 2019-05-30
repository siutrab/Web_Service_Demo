#pragma once
#include "QueueItem.h"
#include "Client.h"
#include <string>


using std::string;

class Client;
class QueueItem;

class Request
	: public Content<string>
{
public:
	Request(string& content);
	~Request();
};
