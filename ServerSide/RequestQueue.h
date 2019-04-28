#pragma once
#include "TranslatorXml.h"
#include "QueueTemplate.h"
#include <memory>

using std::queue;
using std::unique_ptr;

class Client;
class Request;
class TranslatorXml;

	class RequestQueue
		: public Queue<Request>
	{
	public:
		RequestQueue();

		~RequestQueue();

	};

