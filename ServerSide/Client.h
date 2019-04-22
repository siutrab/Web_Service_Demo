#pragma once
#include "SFML/Network.hpp"
#include "Request.h"
#include "RequestsQueueXML.h"

using sf::TcpSocket;
using sf::Packet;

class Request;
class Response;
class RequestsQueueXml;

	class Client
	{
			const unsigned int index;
			TcpSocket socket;
			static RequestsQueueXml* requestQueuePtr;

		// Methods
		void sendResponse();		/// CHANGE ME!!!
	public:
		Client(const unsigned int index);
		~Client();
		void receivePacket();
		// Getters
		TcpSocket* getSocket();
		unsigned int getIndex() const;
		static void setRequestQueuePtr(RequestsQueueXml* const pointer);
	};

