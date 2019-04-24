#pragma once
#include <string>

using std::string;

class ExceptionInterface
{
protected:
	string value;
public:
	string& getValue()
	{
		return value;
	}
};

struct DatabaseExceptions
{

	struct QueryException
	{
		struct WrongTableName
			: public ExceptionInterface
		{
			WrongTableName()
			{
				value = "Wrong table name";
			}
		};
	};
};