#pragma once
#include <string>
#include <utility>
#include <vector>
#include "MappingInterface.h"
#include "Query.h"
#include "boost/lexical_cast.hpp"
#include "boost/lexical_cast/bad_lexical_cast.hpp"

using std::string;

class ParameterInterface
{
public:
	virtual void* getValue() = 0;
	virtual string& getXmlName() = 0;
	virtual bool setValue(string& valueString) = 0;
};


template<typename T>
class Parameter
	: public ParameterInterface
{
	T value;
	string nameXml;
public:
	Parameter(string& nameXml)
		:	nameXml(nameXml)

	{	}

	bool setValue(string& valueString) override
	{
		try
		{
			value = boost::lexical_cast<T>(valueString);
			return true;
		}
		catch(boost::bad_lexical_cast)
		{
			return false;
		}
	}

	void* getValue() override { return &value; }
	string& getXmlName() override { return nameXml; }
};


class MethodInterface
{
protected:
	typedef std::pair<string&, unique_ptr<ParameterInterface>> argument;

	std::vector<argument> parametersArray;

public:
	virtual ~MethodInterface() {}
	virtual void mapArguments(DocumentXml& document) = 0;
	virtual shared_ptr<Query> generateQuery() = 0;
	//virtual std::vector<argument>* getArguments() = 0;
	virtual unique_ptr<string> getMethodName() = 0;

};

