#ifndef CLIENT_H
#define CLIENT_H
#pragma once
#include "SFML/Network.hpp"
#include "RequestsQueue.h"



using sf::TcpSocket;
using sf::Packet;

//class Response;
class RequestsQueue;

	class Client
	{
			const unsigned int index;
			TcpSocket socket;
			static RequestsQueue* requestQueuePtr;

		// Methods
		void sendResponse();		/// CHANGE ME!!!
	public:
		Client(const unsigned int index);
		~Client();
		void receivePacket();
		// Getters
		TcpSocket* getSocket();
		unsigned int getIndex() const;
		static void setRequestQueuePtr(RequestsQueue* const pointer);
	};

#endif // !CLIENT_H
