#include "pch.h"
#include "Client.h"
#include "ClientsMenager.h"

 Queue* Client::requestQueuePtr;
 ErrorHandler* Client::errorHandlerPtr;
 ClientsMenager* Client::clientsMenagerPtr;

	void Client::setRequestQueuePtr(Queue* pointer) 
	{ 
		Client::requestQueuePtr = pointer;		// Settet in RequestsQueue object
	}	
	
	void Client::setErrorHandlerPtr(ErrorHandler* const pointer)
	{ 
		Client::errorHandlerPtr = pointer;		// Settet in ErrorQueue object
	}

	void Client::setClientsMenagerPtr(ClientsMenager* const pointer)
	{
		Client::clientsMenagerPtr = pointer;	// Settet in ClientsMenager object
	}

	Client::Client(unsigned int index)
		:	socket(),
			index(index),
			connected(true),
			requestCount(0)
	{
		socket.setBlocking(false);
	}


	Client::~Client()
	{	}


	void Client::sendResponse(string* response)
	{
		sf::Packet packet;
		if (packet << *response)
		{
			socket.send(packet);
			std::cout << *response;
		}
	}


	void Client::receivePacket()
	{
		Packet packet;
		if (socket.receive(packet) == TcpSocket::Done)
		{
			try
			{
				unique_ptr<QueueItem> request = createRequest(packet);
				Client::requestQueuePtr->addItem(std::move(request));
			}
			catch (ExceptionInterface& exception)
			{
				unique_ptr<QueueItem> queueItem = createQueueItem(exception);
				errorHandlerPtr->createError(std::move(queueItem), exception);
			}
		}
	}


	unique_ptr<QueueItem> Client::createRequest(Packet& packet)
	{
		string contentValue;

		if (packet >> contentValue)
		{
			auto request = std::make_unique<Request>(contentValue);
			auto queueItem = std::make_unique<QueueItem>(this, std::move(request));
			return queueItem;
		}
			
		else throw ServerExceptions::ReceivingPacketExceptions::CantUnpackPacket();
	}


	unique_ptr<QueueItem> Client::createQueueItem(ExceptionInterface& exception)
	{
		auto errorResponse = std::make_unique<ErrorMessage>(exception.getValue());
		
		return std::make_unique<QueueItem>(this, std::move(errorResponse));
	}


	TcpSocket* Client::getSocket() 
	{ 
		return &socket; 
	}


	void Client::requestAdded()
	{
		requestCount++;
	}

	void Client::requestRemoved()
	{
		requestCount--;
		if(requestCount == 0 && connected == false)
		{
			clientsMenagerPtr->removeClient(index);
		}
	}


	void Client::setDisconnected()
	{
		connected = false;
	}


	bool Client::isConnected()
	{
		return connected;
	}


	unsigned int Client::getIndex() const 
	{ 
		return index; 
	}
