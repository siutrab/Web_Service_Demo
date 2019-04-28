#pragma once
#include "Client.h"
#include "RequestHandler.h"
#include "Request.h"
#include <memory>
#include "QueueTemplate.h"

using std::queue;
using std::unique_ptr;

class Client;
class Request;

	class RequestQueue
		: public Queue<Request>
	{
	public:
		RequestQueue();

		~RequestQueue();

	};

