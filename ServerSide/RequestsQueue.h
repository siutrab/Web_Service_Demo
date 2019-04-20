#pragma once
#include "Client.h"
#include "QueueTemplate.h"
#include <queue>
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