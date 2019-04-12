#include "pch.h"
#include "Request.h"


	Request::Request(Client& client)
		: clientPointer(&client)
	{	}

	Request::~Request()
	{	}

	Request* Request::unpackPacket(sf::Packet& packet, Client& client)
	{
		Request* request = new Request(client);

		if (packet >> request->content)
			request->correct = true;

		return request;
	}

	bool Request::isCorrect() { return correct; }
	std::string* Request::getRequest() { return &content; }