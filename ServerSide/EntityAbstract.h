#pragma once
#include "jdbc/cppconn/sqlstring.h"
#include <vector>
#include "boost/any.hpp"

struct ColumnAbstract
{
	boost::any value;
	virtual std::string getValueAsString() = 0;
	virtual std::string getName() = 0;
};

class EntityAbstract
{
public:
	virtual std::vector<ColumnAbstract*>* getVectorFields() = 0;
	virtual unsigned short getFieldsNumber() = 0;
	virtual std::string getTableName() = 0;
	//virtual std::pair<std::string, std::string>* getPair(unsigned int index) = 0;
};

