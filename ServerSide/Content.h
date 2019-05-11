#pragma once

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
		: contentValue(value),
		valid(true)
	{	}

	~Content() override {	}
	bool isValid() override { return valid; }
	void recognizeInvalid() override { valid = false; }
	void* getContent() override { return &contentValue; }
};
