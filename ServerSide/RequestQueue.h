#pragma once
#include "RequestTranslatorXml.h"
#include "Queue.h"
#include <memory>

using std::queue;
using std::unique_ptr;

class Client;
class Request;
class RequestTranslatorXml;

	class RequestQueue
		: public Queue
	{
	public:
		RequestQueue();
		~RequestQueue();
	};

