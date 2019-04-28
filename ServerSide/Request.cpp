#include "pch.h"
#include "Request.h"


Request::Request(Client* client, string& content)
	: QueueItem<string>(client, content)
{
		
}

Request::~Request()
{	}

shared_ptr<Request> Request::unpackPacket(Packet& packet, Client* client)
{
		
	string contentValue;

	if (packet >> contentValue)
	{
		shared_ptr<Request>request(new Request(client, contentValue));
		std::cout << *request->getContent() << std::endl;
		return request;
	}

	else throw ServerExceptions::ReceivingPacketExceptions::CantUnpackPacket();

}

