#pragma once
#include "MethodInterface.h"
#include "MaterialEntity.h"
#include "boost/lexical_cast.hpp"
#include "boost/lexical_cast/bad_lexical_cast.hpp"

using std::string;

class CreateMethod
	: public MethodInterface
{
private:
	struct ParametersCollection
	{	
		string lambda = "lambda";
		string price = "price";
		string name = "name";
		string link = "link";
		string materialType = "type";
		string producer = "producer";
	};

		static ParametersCollection parametersCollection;

		typedef shared_ptr<ParameterInterface> parameter;
		static std::vector<parameter> parametersList;
		shared_ptr<vector<unsigned short>> widthsList;

		DocumentXml* documentXml;

		vector<unique_ptr<MaterialEntity>> generateEntities();
	bool initializeWidthsList();

public:
	CreateMethod();
	~CreateMethod();
	void mapArguments(DocumentXml& document) override;
	shared_ptr<Query> generateQuery() override;
	//std::vector<argument>* getArguments() override;
	unique_ptr<string> getMethodName() override;

};
