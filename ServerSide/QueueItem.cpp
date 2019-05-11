#include "pch.h"
#include "QueueItem.h"
#include "Client.h"

QueueItem::QueueItem(Client* const client, unique_ptr<ContentInterface> content)
	:	client(client),
		content(std::move(content))
{
	client->requestAdded();
}

QueueItem::~QueueItem()
{
	client->requestRemoved();
}

void QueueItem::changeContent(unique_ptr<ContentInterface>& newContent)
{
	content.reset(newContent.release());
}

unsigned int QueueItem::getId() const 
{ 
	return id;
}

Client* QueueItem::getClientPointer() 
{ 
	return client; 
}

unique_ptr<ContentInterface> QueueItem::getContentObject() 
{
	return std::move(content); 
}

void* QueueItem::getContent() 
{ 
	return content->getContent(); 
}