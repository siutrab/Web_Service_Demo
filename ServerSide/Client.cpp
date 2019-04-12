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
	{

	}

	void Client::receivePacket()
	{
		sf::Packet packet;
		if (socket.receive(packet) == sf::Socket::Done)
		{
			Request* conversation = Request::unpackPacket(packet, *this);
			
			if (conversation->isCorrect())
				Client::requestQueuePtr->addRequest(conversation);

			else delete conversation;
		}
	}

// getters
	sf::TcpSocket* Client::getSocket() { return &socket; }
	unsigned int Client::getIndex() const { return index; }

	void Client::setRequestQueuePtr(RequestsQueue* pointer) 
	{ 
		Client::requestQueuePtr = pointer; // Settet in RequestsQueue object
		const_cast<const RequestsQueue*>(Client::requestQueuePtr);
	}