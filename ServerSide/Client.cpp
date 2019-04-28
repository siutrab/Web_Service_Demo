#include "pch.h"
#include "Client.h"

 RequestQueue* Client::requestQueuePtr;

	Client::Client(unsigned int index)
		:	socket(),
			index(index)
	{
		socket.setBlocking(false);
	}

	Client::~Client()
	{	}

// methods
	void Client::sendResponse()
	{	}

	void Client::receivePacket()
	{
		Packet packet;
		if (socket.receive(packet) == TcpSocket::Done)
		{
			try
			{
				shared_ptr<Request> request = Request::unpackPacket(packet, this);
				Client::requestQueuePtr->addItem(request);
			}
			catch (ExceptionInterface& e)
			{

			}
		}
	}

// getters
	TcpSocket* Client::getSocket() { return &socket; }
	unsigned int Client::getIndex() const { return index; }

	void Client::setRequestQueuePtr(RequestQueue* pointer) 
	{ 
		Client::requestQueuePtr = pointer; // Settet in RequestsQueue object
		const_cast<const RequestQueue*>(Client::requestQueuePtr);
	}