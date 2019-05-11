#pragma once
#include <memory>
#include "Content.h"

using std::unique_ptr;

class Client;

class QueueItem
{
protected:
		unsigned int id;
		Client* client;
		unique_ptr<ContentInterface> content;

public:
	QueueItem(Client* const client, unique_ptr<ContentInterface> content);

	~QueueItem();
	
	void changeContent(unique_ptr<ContentInterface>& newContent);

	unsigned int getId() const;
	Client* getClientPointer();
	unique_ptr<ContentInterface> getContentObject();
	void* getContent();
};

