#pragma once
#include <memory>
#include "Content.h"

using std::unique_ptr;

class Client;

class QueueItem
{
protected:
		int id;
		Client* client;
		unique_ptr<ContentInterface> content;

public:
	QueueItem(Client* const client, unique_ptr<ContentInterface> content);

	~QueueItem();
	
	void changeContent(unique_ptr<ContentInterface>& newContent);	// replaces content objest

	unsigned int getId() const;
	void setId(int id);
	bool idIsKnown();
	Client* getClientPointer();
	unique_ptr<ContentInterface> getContentObject();
	void* getContent();
};

