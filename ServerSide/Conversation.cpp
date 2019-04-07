#include "pch.h"
#include "Conversation.h"


Conversation::Conversation()
{
}


Conversation::~Conversation()
{
}

Conversation* Conversation::unpackPacket(sf::Packet* packet)
{
	Conversation* conversation = new Conversation();
	
	if ((*packet) >> conversation->content)
	{
		conversation->correct = true;
	}
	/*delete packet;
	packet = nullptr;*/
	return conversation;
}


bool Conversation::isCorrect() { return correct; }

std::string* Conversation::getRequest() { return &content; }
// Setters
void Conversation::setConversationIndex(unsigned int index) { this->conversationIndex = index; }
