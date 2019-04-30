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
				//shared_ptr<Request> request = Request::unpackPacket(packet, this);
				//Client::requestQueuePtr->addItem(request);
				Request request = unpackPacket(packet);
				auto queueItem = createQueueItem(request);
				requestQueuePtr->addItem(queueItem);
			}
			catch (ExceptionInterface& e)
			{

			}
		}
	}

	Request Client::unpackPacket(Packet& packet)
	{

		string contentValue;

		if (packet >> contentValue)
		{
			//shared_ptr<Request>request(new Request(contentValue));
			//std::cout << request->getContent() << std::endl;
			return Request(contentValue);
		}

		else throw ServerExceptions::ReceivingPacketExceptions::CantUnpackPacket();

	}

	shared_ptr<QueueItem> Client::createQueueItem(Request &request)
	{
		return shared_ptr<QueueItem>(new QueueItem(this, request));
	}

// getters
	TcpSocket* Client::getSocket() { return &socket; }
	unsigned int Client::getIndex() const { return index; }

	void Client::setRequestQueuePtr(RequestQueue* pointer) 
	{ 
		Client::requestQueuePtr = pointer; // Settet in RequestsQueue object
		const_cast<const RequestQueue*>(Client::requestQueuePtr);
	}