#pragma once
#include "QueueItem.h"
#include "ExceptionsSystem.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class ExceptionInterface;

class ErrorResponse
	:	public Content<string>
{
public:
	ErrorResponse(string& exception);
	~ErrorResponse();
};

