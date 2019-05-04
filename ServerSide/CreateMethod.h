#pragma once
#include "DocumentXml.h"
#include "QueryGenerator.h"
#include "boost/lexical_cast.hpp"
#include "boost/lexical_cast/bad_lexical_cast.hpp"
#include <memory>
#include <string>
#include <algorithm>

using std::shared_ptr;
using std::string;

class QueryGenerator;


class CreateMethod
	: public MethodInterface
{
private:
	struct ParametersCollection
	{	
		static string lambda;
		static string price;
		static string name;
		static string link;
		static string materialType;
		static string producer;
	};


	typedef unique_ptr<ParameterInterface> parameter;
		vector<parameter> parametersList;
		unique_ptr<vector<unsigned short>> widthsList;

		DocumentXml* documentXml;
		QueryGenerator* queryGenerator;

	vector<unique_ptr<EntityInterface>> generateEntities();
	bool initializeWidthsList();
	bool mapArguments();

public:
	CreateMethod();
	~CreateMethod();
	unique_ptr<Query> generateQuery(DocumentXml& document) override;
	unique_ptr<string> getMethodName() override;

};
