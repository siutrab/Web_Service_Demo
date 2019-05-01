#include "pch.h"
#include "Request.h"


Request::Request(string& content)
	: Content<string>(content)
{
		
}

//Request::Request(Request& request)
//	//: contentValue(request.getContent()),
//{
//	this->contentValue = request.getContent()
//}

Request::~Request()
{	}

//shared_ptr<Request> Request::unpackPacket(Packet& packet, Client* client)
//{
//		
//	string contentValue;
//
//	if (packet >> contentValue)
//	{
//		shared_ptr<Request>request(new Request(contentValue));
//		std::cout << request->getContent() << std::endl;
//		return request;
//	}
//
//	else throw ServerExceptions::ReceivingPacketExceptions::CantUnpackPacket();
//
//}

