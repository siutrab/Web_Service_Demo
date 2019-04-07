#include "pch.h"
#include "Client.h"

	RequestsQueue* Client::requestsQueue;

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
	void Client::addRequest(Conversation* message)
	{
		Client::requestsQueue->addConversation(message);
	}

	void Client::sendResponse()
	{

	}

	void Client::receivePacket()
	{
		sf::Packet* packet = new sf::Packet();
		if (socket.receive(*packet) == sf::Socket::Done)
		{
			Conversation* conversation = Conversation::unpackPacket(packet);	// constructor called!!! need to be deleted
			if (conversation->isCorrect())
			{
				addRequest(conversation);
			}
			else delete conversation;
		}
		// delete packet; !!!!
	}

// getters
	sf::TcpSocket* Client::getSocket() { return &socket; }
	unsigned int Client::getIndex() const { return index; }

	unsigned int Client::setIndex() 
	{ 
		Client* clientPtr = this;
		return (int)(clientPtr); 
	}
// setters
	void Client::setRequestQueuePointer(RequestsQueue* requestQueue) { requestsQueue = requestQueue; }