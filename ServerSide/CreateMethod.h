#pragma once
#include "MethodInterface.h"

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
		string width = "width";
	};

		static ParametersCollection parametersCollection;

		typedef shared_ptr<ParameterInterface> parameter;
		static std::vector<parameter> parametersList;

		DocumentXml* documentXml;
public:
	CreateMethod();
	~CreateMethod();
	void mapArguments(DocumentXml& document) override;
	std::vector<argument>* getArguments() override;
	unique_ptr<string> getMethodName() override;

};
