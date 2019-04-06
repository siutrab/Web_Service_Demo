#include "pch.h"
#include "Client.h"


	Client::Client(unsigned int index)
		:	socket(),
			index(index)
	{

	}

	Client::~Client()
	{

	}

// methods
	void Client::addRequest(Conversation* message)
	{

	}

	void Client::sendResponse()
	{

	}

	void Client::receivePacket()
	{
		sf::Packet* packet  = new sf::Packet();
		if (socket.receive(*packet) == sf::Socket::Done)
		{
			Conversation* conversation = Conversation::unpackPacket(packet);	// constructor called!!! need to be deleted
			if (conversation->isCorrect())
			{
				addRequest(conversation);
			}
			else delete conversation;
		}
		delete packet;
	}

// getters
	sf::TcpSocket* Client::getSocket() { return &socket; }
	unsigned int Client::getIndex() const { return index; }

// setters
	void Client::setIndex(unsigned int index) { this->index = index; }