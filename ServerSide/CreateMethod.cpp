#include "CreateMethod.h"

string CreateMethod::ParametersCollection::lambda = "lambda";
string CreateMethod::ParametersCollection::price = "price";
string CreateMethod::ParametersCollection::name = "name";
string CreateMethod::ParametersCollection::link = "link";
string CreateMethod::ParametersCollection::materialType = "type";
string CreateMethod::ParametersCollection::producer = "producer";


typedef shared_ptr<ParameterInterface> parameter;

//CreateMethod::ParametersCollection CreateMethod::parametersCollection;

std::vector<parameter> CreateMethod::parametersList
{
	parameter(new Parameter<float>(ParametersCollection::lambda)),
	parameter(new Parameter<float>(ParametersCollection::price)),
	parameter(new Parameter<string>(ParametersCollection::name)),
	parameter(new Parameter<string>(ParametersCollection::link)),
	parameter(new Parameter<string>(ParametersCollection::materialType)),
	parameter(new Parameter<string>(ParametersCollection::producer))
};

vector<unique_ptr<MaterialEntity>> CreateMethod::generateEntities()
{
	vector<unique_ptr<MaterialEntity>> materialsVactor;

	float lambda = *static_cast<float*>(parametersList[0]->getValue());
	float price = *static_cast<float*>(parametersList[1]->getValue());
	string* name = static_cast<string*>(parametersList[2]->getValue());
	string* link = static_cast<string*>(parametersList[3]->getValue());
	string* materialType = static_cast<string*>(parametersList[4]->getValue());
	string* producer = static_cast<string*>(parametersList[5]->getValue());
		
	float priceToLambda = price / lambda;

	for (size_t i = 0; i < widthsList->size(); i++)
	{
		unsigned short width = (*widthsList)[i];
		materialsVactor.push_back(unique_ptr<MaterialEntity>(new MaterialEntity(NULL, lambda, price, priceToLambda, width, *name, *link, *materialType, *producer)));
	}
	return materialsVactor;
}


CreateMethod::CreateMethod()
{
}


CreateMethod::~CreateMethod()
{
}

void CreateMethod::mapArguments(DocumentXml& document)
{
	string parentNodeName = "method";
	documentXml = &document;
	
	for (size_t i = 0; i < parametersList.size(); i++)
	{
		try
		{
			unique_ptr<string> parameterValue = document.getNodeValue(parametersList[i]->getXmlName(), parentNodeName);
			parametersList[i]->setValue(*parameterValue);
		}
		catch (ExceptionInterface& e)
		{
			document.recognizeInvalid();
			document.addException(e);
		}
	}
}

bool CreateMethod::initializeWidthsList()
{
	string parentNodeName = "widths";

	try
	{
		widthsList = documentXml->getChildrenNodesValues<unsigned short>(parentNodeName);
		return true;
	}
	catch(boost::bad_lexical_cast e)
	{
		return false;
	}
}


shared_ptr<Query> CreateMethod::generateQuery()
{
	return shared_ptr<Query>(new Query());
}


unique_ptr<string> CreateMethod::getMethodName()
{
	return unique_ptr<string>(new string("create"));
}