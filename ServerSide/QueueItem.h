#pragma once
#include <memory>

using std::shared_ptr;
class Client;

template<typename T>
class Content
{
template <typename> friend class QueueItem;
protected:
		bool valid;
		T contentValue;

public:
	Content(T& content)
		:	contentValue(content)
	{};
	~Content(){}
	bool isValid() { return valid; }
	bool recognizeInvalid() { valid = false; }
	//T* getContent() { return contentValue; }
	//void setContent(T& content) {contentValue = content; }
};

template<typename T>
class QueueItem
{
protected:
		unsigned int id;
		Client* client;
		Content<T> content;


public:
	QueueItem(Client* client, T& content)
		:	client(client),
			content(content)
	{	}

	~QueueItem() {}

	unsigned int getId() const { return id; }
	Client* getClient() { return client; }
	T* getContent() 
	{
		return &content.contentValue;
	}
	
	template<typename T>
	bool changeContent(T* newContent)
	{
		content.reset(newContent);
	}
};

