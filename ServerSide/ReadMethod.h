#pragma once
#include "MethodInterface.h"
#include "QueryGenerator.h"

using std::string;

class ReadMethod
	: public MethodInterface
{
	QueryGenerator* queryGenerator;

public:
	ReadMethod(QueryGenerator* queryGenerator);
	~ReadMethod();

	unique_ptr<Query> generateQuery(DocumentXml& document) override;
	unique_ptr<string> getMethodName() override;
	bool isResulting() override;
};

