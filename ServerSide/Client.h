#pragma once
#include <vector>
#include <unordered_map>
#include "SFML/Network.hpp"
#include "Conversation.h"

class Conversation;
class Response;

	class Client
	{
		unsigned int index;

		sf::TcpSocket socket;

		// Methods
			void addRequest(Conversation* message);
			void sendResponse();		/// CHANGE ME!!!

	public:
			Client(unsigned int index);
			~Client();

		// Methods
			void			receivePacket();
		// Getters
			sf::TcpSocket*	getSocket();
			unsigned int	getIndex() const;
		// Setters
			void			setIndex(unsigned int index);
	};

