#pragma once
#include <memory>


using std::unique_ptr;

class Client;


class ContentInterface
{
public:
	virtual ~ContentInterface() = 0 {}
	virtual bool isValid() = 0;
	virtual void recognizeInvalid() = 0;
	virtual void* getContent() = 0;
};


template<typename T>
class Content
	: public ContentInterface
{
protected:
		T contentValue;
		bool valid;

public:
	Content(T& value)
		:	contentValue(value),
			valid(true)
	{	}

	~Content() override {	}
	bool isValid() override { return valid; }
	void recognizeInvalid() override { valid = false; }
	void* getContent() override { return &contentValue; }
};


class QueueItem
{
protected:
		unsigned int id;
		Client* client;
		unique_ptr<ContentInterface> content;

public:
	QueueItem(Client* const client, unique_ptr<ContentInterface> content)
		:	client(client),
			content(std::move(content))
	{	}
	

	~QueueItem() {}
	
	void changeContent(unique_ptr<ContentInterface>& newContent)
	{
		//auto newContentPointer = unique_ptr<ContentInterface>(&newContent);
		content.reset(newContent.release());
	}

	unsigned int getId() const { return id; }
	Client* getClientPointer() { return client; }
	unique_ptr<ContentInterface> getContentObject() { return std::move(content); }
	void* getContent() { return content->getContent(); }
};

