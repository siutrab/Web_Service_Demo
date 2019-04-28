#ifndef CLIENT_H
#define CLIENT_H
#pragma once
#include "SFML/Network.hpp"
#include "RequestsQueue.h"



using sf::TcpSocket;
using sf::Packet;

//class Response;
class RequestQueue;

	class Client
	{
			const unsigned int index;
			TcpSocket socket;
			static RequestQueue* requestQueuePtr;

		// Methods
		void sendResponse();		/// CHANGE ME!!!
	public:
		Client(const unsigned int index);
		~Client();
		void receivePacket();
		// Getters
		TcpSocket* getSocket();
		unsigned int getIndex() const;
		static void setRequestQueuePtr(RequestQueue* const pointer);
	};

#endif // !CLIENT_H
