#pragma once
#include "DocumentXml.h"
#include "boost/lexical_cast.hpp"
#include "boost/lexical_cast/bad_lexical_cast.hpp"
#include <memory>
#include <string>

using std::shared_ptr;
using std::string;

class DocumentXml;
class Query;

class CreateMethod
	: public MethodInterface
{
private:
	struct ParametersCollection
	{	
		static string lambda;// = "lambda";
		static string price;// = "price";
		static string name;// = "name";
		static string link;// = "link";
		static string materialType;// = "type";
		static string producer;// = "producer";
	};


		typedef shared_ptr<ParameterInterface> parameter;
		static std::vector<parameter> parametersList;
		shared_ptr<vector<unsigned short>> widthsList;

		DocumentXml* documentXml;

	vector<unique_ptr<MaterialEntity>> generateEntities();
	bool initializeWidthsList();
	void mapArguments(DocumentXml& document) override;

public:
	CreateMethod();
	~CreateMethod();
	shared_ptr<Query> generateQuery() override;
	unique_ptr<string> getMethodName() override;

};
