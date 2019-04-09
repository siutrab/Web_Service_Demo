#pragma once
#include "SFML/Network.hpp"
#include "RequestResponseObject.h"
#include "RequestsQueue.h"

class RequestResponseObject;
class Response;
class RequestsQueue;

	class Client
	{
			const unsigned int index;
			sf::TcpSocket socket;
			static RequestsQueue* requestQueuePtr;

		// Methods
		void sendResponse();		/// CHANGE ME!!!
	public:
		Client(const unsigned int index);
		~Client();
		void receivePacket();
		// Getters
		sf::TcpSocket* getSocket();
		unsigned int getIndex() const;
		static void setRequestQueuePtr(RequestsQueue* const pointer);
	};

