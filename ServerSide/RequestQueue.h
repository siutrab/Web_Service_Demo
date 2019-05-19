#pragma once
#include "TranslatorFromXml.h"
#include "Queue.h"
#include <memory>

using std::queue;
using std::unique_ptr;

class Client;
class Request;
class TranslatorFromXml;

	class RequestQueue
		: public Queue
	{
	public:
		RequestQueue();
		~RequestQueue();
	};

