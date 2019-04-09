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
	{

	}

// methods
	void Client::sendResponse()
	{

	}

	void Client::receivePacket()
	{
		sf::Packet packet;
		if (socket.receive(packet) == sf::Socket::Done)
		{
			RequestResponseObject* conversation = RequestResponseObject::unpackPacket(packet);
			if (conversation->isCorrect())
			{
				Client::requestQueuePtr->addRequest(conversation);
			}
			else delete conversation;
		}
	}

// getters
	sf::TcpSocket* Client::getSocket() { return &socket; }
	unsigned int Client::getIndex() const { return index; }

	void Client::setIndex(unsigned int index) 
	{ 
		this->index = index;
	}

	void Client::setRequestQueuePtr(RequestsQueue* pointer) { Client::requestQueuePtr = pointer; }