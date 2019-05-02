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
	T getContent() { return contentValue; }
};


class QueueItem
{
protected:
		unsigned int id;
		Client* client;
		unique_ptr<ContentInterface> content;

public:
	QueueItem(Client* const client, ContentInterface& content)
		:	client(client),
			content(&content)
	{	}
	//QueueItem() {}
	//QueueItem(QueueItem&& queueItem)
	//	:	id(queueItem.id),
	//		client(queueItem.client)
	//{
	//	ContentInterface* contentPtr = queueItem.content.release();
	//	content = unique_ptr<ContentInterface>(contentPtr);
	//}

	~QueueItem() {}
	
	void changeContent(ContentInterface& newContent)
	{
		auto newContentPointer = unique_ptr<ContentInterface>(&newContent);
		content.swap(newContentPointer);
	}

	unsigned int getId() const { return id; }
	Client* getClientPointer() { return client; }
	unique_ptr<ContentInterface>& getContent() { return content; }
};

