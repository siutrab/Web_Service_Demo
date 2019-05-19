#pragma once
#include "Query.h"
#include "jdbc/cppconn/resultset.h"
#include "boost/lexical_cast.hpp"
#include "boost/lexical_cast/bad_lexical_cast.hpp"
#include <string>
#include <memory>
#include <utility>
#include <vector>

using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::vector;
using sql::ResultSet;


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
			char character = str[i];
			if (character != ' ' && character != '\n' && character != '\r' && character != '\t' && character != '\v' && character != '\f')
				newStr += character;
		}
		str = newStr;
	}

	void* getValue() override 
	{ 
		return &value; 
	}

	string& getXmlName() override 
	{ 
		return nameXml; 
	}
};


class MethodInterface
{
protected:
	typedef std::pair<string&, unique_ptr<ParameterInterface>> argument;

	std::vector<argument> parametersArray;
public:
	virtual ~MethodInterface() {}
	virtual unique_ptr<Query> generateQuery(DocumentXml& document) = 0;
	virtual unique_ptr<string> getMethodName() = 0;
	virtual bool isResulting() = 0;
};


class CreateMethodInterface
	: public MethodInterface
{
	

};


class ReadMethodInterface
	: public MethodInterface
{
public:
	virtual vector<unique_ptr<EntityInterface>> generateEntities(shared_ptr<ResultSet> resultSet) = 0;
};