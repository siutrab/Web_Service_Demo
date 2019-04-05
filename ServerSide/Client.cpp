#include "pch.h"
#include "Client.h"


Client::Client(unsigned int index)
	:	socket(),
		requestsNumber(0),
		responsesNumber(0),
		index(index)
		
{

}


Client::~Client()
{
	for (int i = 0; i < requests.size(); i++)
	{
		delete requests[i];
		requests[i] = nullptr;
	}
	for (int i = 0; i < responses.size(); i++)
	{
		delete responses[i];
		responses[i] = nullptr;
	}
}

// methods
void Client::addRequest(Request* message)
{
	requests.push_back(message);
	message->setConversationIndex(conversationUniqueNumber);
	conversationUniqueNumber++;
	requestsNumber++;
}

void Client::sendResponse()
{
	delete requests[0];
	requests[0] = nullptr;
	requests.erase(requests.begin());	// deleting the first element of vector
	offset++;
}

void Client::receivePacket()
{
	sf::Packet packet;
	if (socket.receive(packet) == sf::Socket::Done)
	{
		Request* message = Request::unpackPacket(packet);
		if (message->isCorrect())
		{
			addRequest(message);
		}
	}
}


// getters
 sf::TcpSocket* Client::getSocket() { return &socket; }
unsigned int Client::getIndex() const { return index; }
int Client::getRealRequestIndex(unsigned int index) { return index - offset; }
//unsigned int Client::getRequestNumber() const { return requestsNumber; }
//unsigned int Client::getResponseNumber() const { return responsesNumber; }

// setters
void Client::setIndex(unsigned int index) { this->index = index; }