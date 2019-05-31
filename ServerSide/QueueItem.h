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
	bool idIsKnown();												// returns true if its possible to identify requests id
	Client* getClientPointer();
	unique_ptr<ContentInterface> getContentObject();				// returns content as an object
	void* getContent();												// returns content as value (pointer to a value)
};

