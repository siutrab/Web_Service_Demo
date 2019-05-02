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
				Request request = unpackPacket(packet);
				///
					std::cout << request.getContent() << std::endl;	//////////////////////// COUT
				///
				unique_ptr<QueueItem> queueItem = createQueueItem(request);
				Client::requestQueuePtr->addItem(*queueItem);
			}
			catch (ExceptionInterface& exception)
			{
				unique_ptr<QueueItem> queueItem = createQueueItem(exception);
				errorQueuePtr->addItem(*queueItem, exception);
			}
		}
	}

	Request Client::unpackPacket(Packet& packet)
	{
		string contentValue;

		if (packet >> contentValue)
			return Request(contentValue);
			
		else throw ServerExceptions::ReceivingPacketExceptions::CantUnpackPacket();

	}

	unique_ptr<QueueItem> Client::createQueueItem(Request &request)
	{
		//ContentInterface& content = dynamic_cast<ContentInterface&>(request);
		
		return std::make_unique<QueueItem>(this, request);
	}

	unique_ptr<QueueItem> Client::createQueueItem(ExceptionInterface& exception)
	{
		ErrorResponse errorResponse(exception.getValue());
		

		return std::make_unique<QueueItem>(this, errorResponse);
	}

	TcpSocket* Client::getSocket() { return &socket; }

	unsigned int Client::getIndex() const { return index; }
