#pragma once
#include "SFML/Network.hpp"
#include "Conversation.h"
#include "RequestsQueue.h"

class Conversation;
class Response;
class RequestsQueue;

	class Client
	{
		static RequestsQueue* requestsQueue;
		unsigned int index;
		sf::TcpSocket socket;

		// Methods
			void addRequest(Conversation* message);
			void sendResponse();		/// CHANGE ME!!!
			void setIndex(unsigned int index);

	public:
			Client(unsigned int index);
			~Client();

		// Methods
			void receivePacket();
		// Getters
			sf::TcpSocket* getSocket();
			unsigned int getIndex() const;
		// Setters
			static void setRequestQueuePointer(RequestsQueue* requestQueue);
	};

