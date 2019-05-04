#include "CreateMethod.h"

string CreateMethod::ParametersCollection::lambda = "lambda";
string CreateMethod::ParametersCollection::price = "price";
string CreateMethod::ParametersCollection::name = "name";
string CreateMethod::ParametersCollection::link = "link";
string CreateMethod::ParametersCollection::materialType = "type";
string CreateMethod::ParametersCollection::producer = "producer";


typedef shared_ptr<ParameterInterface> parameter;


std::vector<parameter> CreateMethod::parametersList
{
	parameter(new Parameter<float>(ParametersCollection::lambda)),
	parameter(new Parameter<float>(ParametersCollection::price)),
	parameter(new Parameter<string>(ParametersCollection::name)),
	parameter(new Parameter<string>(ParametersCollection::link)),
	parameter(new Parameter<string>(ParametersCollection::materialType)),
	parameter(new Parameter<string>(ParametersCollection::producer))
};


vector<unique_ptr<EntityInterface>> CreateMethod::generateEntities()
{
	size_t entitiesNumber = widthsList->size();
	vector<unique_ptr<EntityInterface>> materialsVactor(entitiesNumber);

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
		materialsVactor[i] = unique_ptr<EntityInterface>(
			new MaterialEntity(NULL, lambda, price, priceToLambda, width, *name, *link, *materialType, *producer));
	}
	return materialsVactor;
}


CreateMethod::CreateMethod()
{
}


CreateMethod::~CreateMethod()
{
}

void CreateMethod::mapArguments()
{
	string parentNodeName = "method";
	
	
	for (size_t i = 0; i < parametersList.size(); i++)
	{
		try
		{
			unique_ptr<string> parameterValue = documentXml->getNodeValue(parametersList[i]->getXmlName(), parentNodeName);
			parametersList[i]->setValue(*parameterValue);
		}
		catch (ExceptionInterface& e)
		{
			documentXml->recognizeInvalid();
			documentXml->addException(e);
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


unique_ptr<Query> CreateMethod::generateQuery(DocumentXml& document)	//////// TOOOOOOOOOOOOOOOOOOOOOOOOO DOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
{
	documentXml = &document;
	initializeWidthsList();
	mapArguments();
	vector<unique_ptr<EntityInterface>> entitiesVector = generateEntities();
	sql::SQLString& query = *queryGenerator->insert(entitiesVector);

	return unique_ptr<Query>(new Query(query));
}


unique_ptr<string> CreateMethod::getMethodName()
{
	return unique_ptr<string>(new string("create"));
}