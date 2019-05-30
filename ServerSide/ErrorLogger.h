#pragma once
#include "ExceptionsSystem.h"
#include <fstream>
#include <time.h>
#include <string>
#include <sstream>


using std::string;
using std::stringstream;

class ErrorLogger
{
	static const string path;
	std::fstream file;

	bool openFile();
	string preapareDate();
public:
	ErrorLogger();
	~ErrorLogger();
	void logError(ExceptionInterface& exception);	// saves log in txt file
};

