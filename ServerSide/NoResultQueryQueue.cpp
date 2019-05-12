#include "NoResultQueryQueue.h"
//#include "resultQueryQueue.h"


NoResultQueryQueue::NoResultQueryQueue()
{
	TranslatorXml::setNoResultQueryQueuePtr(this);
	DatabaseHandler::setNoResultQueryQueuePtr(this);
}


NoResultQueryQueue::~NoResultQueryQueue()
{
}


