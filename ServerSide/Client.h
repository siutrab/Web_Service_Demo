#pragma once
#include "SFML/Network.hpp"
#include "RequestQueue.h"
#include <memory>

using std::unique_ptr;
using sf::TcpSocket;
using sf::Packet;

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

