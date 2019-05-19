#include "CreateMethod.h"

string CreateMethodMaterials::ParametersCollection::lambda = "lambda";
string CreateMethodMaterials::ParametersCollection::price = "price";
string CreateMethodMaterials::ParametersCollection::name = "name";
string CreateMethodMaterials::ParametersCollection::link = "link";
string CreateMethodMaterials::ParametersCollection::materialType = "type";
string CreateMethodMaterials::ParametersCollection::producer = "producer";


typedef unique_ptr<ParameterInterface> parameter;


vector<unique_ptr<EntityInterface>> CreateMethodMaterials::generateEntities()
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
		materialsVactor[i] = std::move(unique_ptr<EntityInterface>(
			new MaterialEntity(NULL, lambda, price, priceToLambda, width, *name, *link, *materialType, *producer)));
	}
	return materialsVactor;
}


CreateMethodMaterials::CreateMethodMaterials(QueryGenerator* queryGenerator)
	:	parametersList(),
		queryGenerator(queryGenerator)
{
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<float>(ParametersCollection::lambda)));
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<float>(ParametersCollection::price)));
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<string>(ParametersCollection::name)));
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<string>(ParametersCollection::link)));
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<string>(ParametersCollection::materialType)));
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<string>(ParametersCollection::producer)));
}


CreateMethodMaterials::~CreateMethodMaterials()
{
}

bool CreateMethodMaterials::mapArguments()
{
	for (size_t i = 0; i < parametersList.size(); i++)
	{
		string argumentName = parametersList[i]->getXmlName();
		auto parameterString = documentXml->getParameter(argumentName);
		bool valueSetted = parametersList[i]->setValue(*parameterString);
		
		if(valueSetted == false)
		{
			return false;
		}
	}

	return true;
}

bool CreateMethodMaterials::initializeWidthsList()
{
	string arrayName = "widths";
	string parameterName = "width";

	auto widthsString = documentXml->getParametersArray(arrayName, parameterName);	// vector of STRINGS!!!
	size_t widthsNumber = widthsString->size();

	typedef vector<unsigned short> usVector;
	auto castedWidths = std::make_unique<usVector>();	// vector of ushort
	// casting
	try
	{
		for (size_t i = 0; i < widthsNumber; i++)
		{
			string stringValue = (*widthsString)[i];
			eraseWhitespaces(stringValue);
			int ushortValue = boost::lexical_cast<int>(stringValue.c_str());

			castedWidths->push_back(ushortValue);
		}
	}
	catch (boost::bad_lexical_cast e)
	{
		std::cout << e.what();
		return false;
	}

	widthsList = std::move(castedWidths);
	return true;
}

void CreateMethodMaterials::eraseWhitespaces(string& str)
{
	string newStr;
	for (size_t i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if (c != ' ')		// erasing only spaces, because the rest of white signes were removed in DocumentXml constructor
			newStr += c;
	}
	str = newStr;
}

unique_ptr<Query> CreateMethodMaterials::generateQuery(DocumentXml& document)
{
	documentXml = &document;
	if ((initializeWidthsList()) && (mapArguments()))
	{
		vector<unique_ptr<EntityInterface>> entitiesVector = generateEntities();
		sql::SQLString query = *queryGenerator->insert(entitiesVector);
		
		auto queryPtr =	std::make_unique<Query>(query);
		return std::move(queryPtr);
	}
	throw ServerExceptions::QueryMappingExceptions::CannotConvertXml();
}

bool CreateMethodMaterials::isResulting()
{
	return false;
}

unique_ptr<string> CreateMethodMaterials::getMethodName()
{
	return unique_ptr<string>(new string("create"));
}