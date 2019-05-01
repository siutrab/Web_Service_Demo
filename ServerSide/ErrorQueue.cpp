#include "ErrorQueue.h"



ErrorQueue::ErrorQueue()
{
	Client::setErrorQueuePtr(this);

}


ErrorQueue::~ErrorQueue()
{
}

