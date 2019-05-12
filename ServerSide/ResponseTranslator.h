#pragma once
#include "Queue.h"
#include "Response.h"
#include <memory>
#include <string>

using std::string;
using std::unique_ptr;

class ResponseTranslator
{
	static const string successMessageFirstPart;
	static const string successMessageSecondPart;

public:
	
	ResponseTranslator();
	~ResponseTranslator();
	unique_ptr<Response> generateSuccessMessage(QueueItem& queueItem);
};

