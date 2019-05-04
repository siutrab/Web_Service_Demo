#include "QueryQueue.h"


QueryQueue::QueryQueue()
{
	TranslatorXml::setQueryQueuePtr(this);
	DatabaseHandler::setQueryQueuePtr(this);
}


QueryQueue::~QueryQueue()
{
}
