#pragma once
#include "DocumentXml.h"
#include "QueryGenerator.h"
#include "boost/lexical_cast.hpp"
#include "boost/lexical_cast/bad_lexical_cast.hpp"
#include <memory>
#include <string>

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

	QueryGenerator* queryGenerator;

	typedef shared_ptr<ParameterInterface> parameter;
		static vector<parameter> parametersList;
		shared_ptr<vector<unsigned short>> widthsList;

		DocumentXml* documentXml;

	vector<unique_ptr<EntityInterface>> generateEntities();
	bool initializeWidthsList();
	void mapArguments();

public:
	CreateMethod();
	~CreateMethod();
	unique_ptr<Query> generateQuery(DocumentXml& document) override;
	unique_ptr<string> getMethodName() override;

};
