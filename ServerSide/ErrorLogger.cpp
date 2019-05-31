#include "ErrorLogger.h"

const string ErrorLogger::path = "errorlog.txt";

ErrorLogger::ErrorLogger()
{	}


ErrorLogger::~ErrorLogger()
{	}

void ErrorLogger::logError(ExceptionInterface& exception)
{
	stringstream log;
	log << exception.getValue() << "\n" 
		<< preapareDate() << "\n\n";

	if (openFile())
	{
		file << log.str();
		file.close();
	}
}

string ErrorLogger::preapareDate()
{
	time_t measuredTime = time(nullptr);
	struct tm localTime;

	localtime_s(&localTime, &measuredTime);
	stringstream todayDate;

	todayDate << (localTime.tm_mday) << "." << (localTime.tm_mon + 1) << "." << (1900 + localTime.tm_year) << " " << (localTime.tm_hour)
		<< ":" << (localTime.tm_min) << ":" << (localTime.tm_sec);

	
	return todayDate.str();
}

bool ErrorLogger::openFile()
{
	file.open(path, std::ios::app);
	return file.good();
}