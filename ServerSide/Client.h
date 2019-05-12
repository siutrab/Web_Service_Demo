#pragma once
#include "ErrorQueue.h"
#include "SFML/Network.hpp"
#include "Queue.h"
#include "QueueItem.h"
#include "Request.h"

#include <memory>

using std::unique_ptr;
using std::shared_ptr;
using sf::TcpSocket;
using sf::Packet;

class Queue;
class Request;
class QueueItem;
class ContentInterface;
class ErrorQueue;
class ClientsMenager;

	class Client
	{
		unsigned int requestCount;
		bool connected;
			const unsigned int index;
			TcpSocket socket;
			static Queue* requestQueuePtr;
			static ErrorQueue* errorQueuePtr;
			static ClientsMenager* clientsMenagerPtr;

		// Methods
		unique_ptr<QueueItem> createRequest(Packet& packet);
		unique_ptr<QueueItem> createQueueItem(ExceptionInterface& exception);
	public:
		Client(const unsigned int index);
		~Client();
		void receivePacket();
		void sendResponse(string* response);		/// CHANGE ME!!!

		void requestAdded();
		void requestRemoved();

		TcpSocket* getSocket();
		bool isConnected();
		unsigned int getIndex() const;
		static void setRequestQueuePtr(Queue* const pointer);
		static void setErrorQueuePtr(ErrorQueue* const pointer);
		static void setClientsMenagerPtr(ClientsMenager* const pointer);
	};

