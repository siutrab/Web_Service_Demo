#pragma once
#include "TranslatorXml.h"
#include "Queue.h"
#include <memory>

using std::queue;
using std::unique_ptr;

class Client;
class Request;
class TranslatorXml;

	class RequestQueue
		: public Queue
	{
	public:
		RequestQueue();

		~RequestQueue();

	};

