#pragma once
#include <memory>

using std::shared_ptr;

class Client;
class Request;

class ContentInterface
{
public:
	virtual ~ContentInterface() = 0 {	}
	virtual bool isValid() = 0;
	virtual void recognizeInvalid() = 0;
};


template<typename T>
class Content
	: public ContentInterface
{
protected:
		bool valid;
		T contentValue;

public:
	Content(T& content)
		:	contentValue(content),
			valid(true)
	{	}
	~Content() override {	}
	bool isValid() override { return valid; }
	void recognizeInvalid() override { valid = false; }
	T& getContent() { return contentValue; }
};


class QueueItem
{
protected:
		unsigned int id;
		Client* client;
		shared_ptr<ContentInterface> content;

public:
	QueueItem(Client* const client, ContentInterface& content)
		:	client(client),
			content(shared_ptr<ContentInterface>(&content))
	{	}


	~QueueItem() {}

	unsigned int getId() const { return id; }
	Client* getClientPointer() { return client; }
	shared_ptr<ContentInterface> getContent() { return content;	}
	
	bool changeContent(shared_ptr<ContentInterface> newContent)
	{
		content.swap(newContent);
	}
};

