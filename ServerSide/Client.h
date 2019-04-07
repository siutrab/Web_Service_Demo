#pragma once
#include "SFML/Network.hpp"
#include "RequestResponseObject.h"
#include "RequestsQueue.h"

class RequestResponseObject;
class Response;
class RequestsQueue;

	class Client
	{
			unsigned int index;
			sf::TcpSocket socket;

		// Methods
		void sendResponse();		/// CHANGE ME!!!
		void setIndex(unsigned int index);
	public:
		Client(unsigned int index);
		~Client();
		void receivePacket();
		// Getters
		sf::TcpSocket* getSocket();
		unsigned int getIndex() const;
	};

