#include "QueryQueue.h"


QueryQueue::QueryQueue()
{
	TranslatorXml::setQueryQueuePtr(this);
}


QueryQueue::~QueryQueue()
{
}
