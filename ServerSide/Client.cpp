#include "pch.h"
#include "Client.h"

 RequestQueue* Client::requestQueuePtr;
 ErrorQueue* Client::errorQueuePtr;

	void Client::setRequestQueuePtr(RequestQueue* pointer) 
	{ 
		Client::requestQueuePtr = pointer; // Settet in RequestsQueue object
		const_cast<const RequestQueue*>(Client::requestQueuePtr);
	}	
	
	void Client::setErrorQueuePtr(ErrorQueue* const pointer)
	{ 
		Client::errorQueuePtr = pointer; // Settet in RequestsQueue object
		const_cast<const ErrorQueue*>(Client::errorQueuePtr);
	}

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
				unique_ptr<QueueItem> request = createRequest(packet);
				///
					std::cout << *(static_cast<string*>(request->getContent())) << std::endl;	//////////////////////// COUT
				///
				Client::requestQueuePtr->addItem(std::move(request));
			}
			catch (ExceptionInterface& exception)
			{
				unique_ptr<QueueItem> queueItem = createQueueItem(exception);
				errorQueuePtr->addItem(std::move(queueItem), exception);
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
		auto errorResponse = std::make_unique<ErrorResponse>(exception.getValue());
		
		return std::make_unique<QueueItem>(this, std::move(errorResponse));
	}

	TcpSocket* Client::getSocket() 
	{ 
		return &socket; 
	}

	unsigned int Client::getIndex() const 
	{ 
		return index; 
	}
