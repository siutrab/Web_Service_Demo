#pragma once
#include "QueueItem.h"
#include "ExceptionsSystem.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class ExceptionInterface;

class ErrorMessage
	:	public Content<string>
{
public:
	ErrorMessage(string& exception);
	~ErrorMessage();
};

