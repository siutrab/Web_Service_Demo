#pragma once
#include "Conversation.h"

class Conversation;
class Response
{
	Conversation* request;
public:
	Response();
	~Response();
};

