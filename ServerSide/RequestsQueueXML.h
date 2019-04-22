#pragma once
#include "Client.h"
#include"TranslatorXML.h"
#include "QueueTemplate.h"
#include "Request.h"
#include "memory"

using std::queue;
using std::unique_ptr;

class Client;
class Request;


	class RequestsQueueXml
		: public Queue<Request>
	{
	public:
		RequestsQueueXml();

		~RequestsQueueXml();

	};
