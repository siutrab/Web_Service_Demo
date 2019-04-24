#include "pch.h"
#include "Client.h"

 RequestsQueue* Client::requestQueuePtr;

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
			Request* request = Request::unpackPacket(packet, *this);
			
			if (request->isCorrect())
				Client::requestQueuePtr->addItem(*request);

			else delete request;
		}
	}

// getters
	TcpSocket* Client::getSocket() { return &socket; }
	unsigned int Client::getIndex() const { return index; }

	void Client::setRequestQueuePtr(RequestsQueue* pointer) 
	{ 
		Client::requestQueuePtr = pointer; // Settet in RequestsQueue object
		const_cast<const RequestsQueue*>(Client::requestQueuePtr);
	}