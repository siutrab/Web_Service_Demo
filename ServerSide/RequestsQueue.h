#pragma once
#include "Client.h"
#include "RequestHandler.h"
#include "QueueTemplate.h"
#include "Request.h"
#include "memory"

using std::queue;
using std::unique_ptr;

class Client;
class Request;


	class RequestsQueue
		: public Queue<Request>
	{
	public:
		RequestsQueue();

		~RequestsQueue();

	};
