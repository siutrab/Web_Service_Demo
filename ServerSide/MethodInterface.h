#pragma once
#include <string>
#include <memory>
#include <utility>
#include <vector>
#include "Query.h"
#include "boost/lexical_cast.hpp"
#include "boost/lexical_cast/bad_lexical_cast.hpp"

using std::string;
using std::shared_ptr;
using std::unique_ptr;

class DocumentXml;
class Query;

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
		eraseWhitespaces(valueString);
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

	void eraseWhitespaces(string& str)
	{
		string newStr;
		for (size_t i = 0; i < str.size(); i++)
		{
			char c = str[i];
			if (c != ' ' && c != '\n' && c != '\r' && c != '\t' && c != '\v' && c != '\f')
				newStr += c;
		}
		str = newStr;
	}


	void* getValue() override { return &value; }
	string& getXmlName() override { return nameXml; }
};


class MethodInterface
{
protected:
	typedef std::pair<string&, unique_ptr<ParameterInterface>> argument;

	std::vector<argument> parametersArray;

	//virtual void mapArguments(DocumentXml& document) = 0;
public:
	virtual ~MethodInterface() {}
	virtual unique_ptr<Query> generateQuery(DocumentXml& document) = 0;
	virtual unique_ptr<string> getMethodName() = 0;

};

