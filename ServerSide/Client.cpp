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
				//shared_ptr<Request> request = Request::unpackPacket(packet, this);
				//Client::requestQueuePtr->addItem(request);
				Request request = unpackPacket(packet);
				///
					std::cout << request.getContent() << std::endl;
				///
				auto queueItem = createQueueItem(request);
				Client::requestQueuePtr->addItem(queueItem);
			}
			catch (ExceptionInterface& exception)
			{
				//ErrorResponse errorResponse(exception.getValue());
				//auto queueItem = createQueueItem(errorResponse);
				//vector<ExceptionInterface> exceptionVevtor;
				//errorQueuePtr->addItem(exception.getValue());
			}
		}
	}

	Request Client::unpackPacket(Packet& packet)
	{

		string contentValue;

		if (packet >> contentValue)
			return Request(contentValue);
			//shared_ptr<Request>request(new Request(contentValue));
			//std::cout << request->getContent() << std::endl;

		else throw ServerExceptions::ReceivingPacketExceptions::CantUnpackPacket();

	}

	shared_ptr<QueueItem> Client::createQueueItem(Request &request)
	{
		ContentInterface& content = static_cast<ContentInterface&>(request);	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//shared_ptr<QueueItem> queueItem = std::static_pointer_cast<
		return shared_ptr<QueueItem>(new QueueItem(this, content));
	}

// getters
	TcpSocket* Client::getSocket() { return &socket; }
	unsigned int Client::getIndex() const { return index; }
