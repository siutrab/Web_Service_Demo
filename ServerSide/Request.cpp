#include "pch.h"
#include "Request.h"


	Request::Request(Client& client)
		: clientPointer(&client)
	{	}

	Request::~Request()
	{	}

	Request* Request::unpackPacket(Packet& packet, Client& client)
	{
		Request* request = new Request(client);

		if (packet >> request->content)
			request->correct = true;
		std::cout << request->content << std::endl;
		return request;
	}

	bool Request::isCorrect() { return correct; }
	string* Request::getRequest() { return &content; }