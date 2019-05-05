#pragma once
#include "ErrorQueue.h"
#include "SFML/Network.hpp"
#include "RequestQueue.h"
#include "QueueItem.h"
#include "Request.h"
#include <memory>

using std::unique_ptr;
using std::shared_ptr;
using sf::TcpSocket;
using sf::Packet;

class RequestQueue;
class Request;
class QueueItem;
class ContentInterface;
class ErrorQueue;

	class Client
	{
			const unsigned int index;
			TcpSocket socket;
			static RequestQueue* requestQueuePtr;
			static ErrorQueue* errorQueuePtr;

		// Methods
		void sendResponse();		/// CHANGE ME!!!
		unique_ptr<QueueItem> createRequest(Packet& packet);
		//unique_ptr<QueueItem> createQueueItem(Request &request);
		unique_ptr<QueueItem> createQueueItem(ExceptionInterface& exception);
	public:
		Client(const unsigned int index);
		~Client();
		void receivePacket();
		// Getters
		TcpSocket* getSocket();
		unsigned int getIndex() const;
		static void setRequestQueuePtr(RequestQueue* const pointer);
		static void setErrorQueuePtr(ErrorQueue* const pointer);
	};

