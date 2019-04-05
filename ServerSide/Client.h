#pragma once
#include <vector>
#include <unordered_map>
#include "SFML/Network.hpp"
#include "Request.h"
#include "Response.h"

class Client
{
/*	unsigned int index;
	unsigned int requestsNumber;
	unsigned int responsesNumber;
	unsigned int conversationUniqueNumber;
	unsigned int offset;*/	// starts from 0 and increases each time when the first element of request vector is solved(removed from vector)

	sf::TcpSocket socket;
	/*
	std::vector<Request*>requests;
	std::vector<Response*>responses;
*/
		// Methods
		void addRequest(Request* message);
		void sendResponse();		/// CHANGE ME!!!
		//int getRealRequestIndex(unsigned int index);	// returns actual index of Request in vector

public:
		Client(unsigned int index);
		~Client();

		// Methods
		void receivePacket();

		// Getters
		sf::TcpSocket* getSocket();
		unsigned int getIndex() const;
		//unsigned int getRequestNumber() const;
		//unsigned int getResponseNumber() const;
		// Setters
		void setIndex(unsigned int index);
};

