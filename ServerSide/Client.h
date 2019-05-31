#pragma once
#include "ErrorHandler.h"
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
class ErrorHandler;
class ClientsMenager;

	class Client
	{
			static Queue* requestQueuePtr;		
			static ErrorHandler* errorHandlerPtr;
			static ClientsMenager* clientsMenagerPtr;
			

			unsigned int requestCount;
			bool connected;
			const unsigned int index;	// index in ClientsMenager, unique for every instance

			TcpSocket socket;
			

		unique_ptr<QueueItem> createRequest(Packet& packet);	// Creates new queueItem
		unique_ptr<QueueItem> createQueueItem(ExceptionInterface& exception);
	public:
		Client(const unsigned int index);
		~Client();
		void receivePacket();					// Receives record form specific socket and if it's correct push it on requesttQueue;
		void sendResponse(string* response);	// Sends response to the client

		TcpSocket* getSocket();
		unsigned int getIndex() const;

		/* 
			Below functions are part of client removeing system
			While Client sends to server disconnection request the flag is setted, 
			but the client istn't destroyed yet, bacause some of its requests are in system.
			Each queue is filtering requests of disconnected clients and removes them.
			Each remove is decrementing the counter until client has no more requests.
			Then he calls ClientsMenager to remove him.
		*/

		void requestAdded();					// Reports that request was added to the specific client
		void requestRemoved();					// Reports request removement. If there ewo
		bool isConnected();
		void setDisconnected();			


		// Below functions set static poiners
		static void setRequestQueuePtr(Queue* const pointer);	
		static void setErrorHandlerPtr(ErrorHandler* const pointer);
		static void setClientsMenagerPtr(ClientsMenager* const pointer);
	};

