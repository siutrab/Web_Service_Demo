#pragma once
#include "Queue.h"
#include "NonResultQuery.h"
#include "TranslatorXml.h"
#include "DatabaseHandler.h"

class NoResultQuery;

class NoResultQueryQueue
	: public Queue
{
public:
	NoResultQueryQueue();
	~NoResultQueryQueue();
};
