#pragma once
#include "jdbc/cppconn/sqlstring.h"
#include <vector>
#include "boost/any.hpp"

using std::string;
using std::vector;


struct ColumnAbstract
{
	boost::any value;
	virtual void setValue(void*) = 0;
	virtual string getValueAsString() = 0;
	virtual string getName() = 0;

};

class EntityInterface
{
public:
	virtual vector<ColumnAbstract*>* getVectorFields() = 0;
	virtual unsigned short getFieldsNumber() = 0;
	virtual string getTableName() = 0;
	//virtual std::pair<std::string, std::string>* getPair(unsigned int index) = 0;
};

