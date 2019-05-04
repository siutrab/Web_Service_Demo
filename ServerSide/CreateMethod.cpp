#include "CreateMethod.h"

string CreateMethod::ParametersCollection::lambda = "lambda";
string CreateMethod::ParametersCollection::price = "price";
string CreateMethod::ParametersCollection::name = "name";
string CreateMethod::ParametersCollection::link = "link";
string CreateMethod::ParametersCollection::materialType = "type";
string CreateMethod::ParametersCollection::producer = "producer";


typedef unique_ptr<ParameterInterface> parameter;

//
//vector<unique_ptr<ParameterInterface>> CreateMethod::parametersList
//{
//	parameter(new Parameter<float>(ParametersCollection::lambda)),
//	parameter(new Parameter<float>(ParametersCollection::price)),
//	parameter(new Parameter<string>(ParametersCollection::name)),
//	parameter(new Parameter<string>(ParametersCollection::link)),
//	parameter(new Parameter<string>(ParametersCollection::materialType)),
//	parameter(new Parameter<string>(ParametersCollection::producer))
//};


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
	:	parametersList()
{
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<float>(ParametersCollection::lambda)));
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<float>(ParametersCollection::price)));
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<string>(ParametersCollection::name)));
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<string>(ParametersCollection::link)));
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<string>(ParametersCollection::materialType)));
	parametersList.push_back(unique_ptr<ParameterInterface>(new Parameter<string>(ParametersCollection::producer)));
}


CreateMethod::~CreateMethod()
{
}

bool CreateMethod::mapArguments()
{
	for (size_t i = 0; i < parametersList.size(); i++)
	{
		string argumentName = parametersList[i]->getXmlName();
		auto parameterString = documentXml->getParameter(argumentName);
		bool valueSetted = parametersList[i]->setValue(*parameterString);
		
		if(!valueSetted)
		{
			return false;
			documentXml->recognizeInvalid();
		}
	}

	return true;
}

bool CreateMethod::initializeWidthsList()
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
			
			// erasing whitespaces -.-
			stringValue.erase(std::remove_if(stringValue.begin(), stringValue.end(),
				[](char c)
				{
					return (c == ' '|| c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f');
				}),
				stringValue.end()
			);

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


unique_ptr<Query> CreateMethod::generateQuery(DocumentXml& document)	//////// TOOOOOOOOOOOOOOOOOOOOOOOOO DOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
{
	documentXml = &document;
	if ((initializeWidthsList()) && (mapArguments()))
	{
		vector<unique_ptr<EntityInterface>> entitiesVector = generateEntities();
		sql::SQLString& query = *queryGenerator->insert(entitiesVector);
		
		return unique_ptr<Query>(new Query(query));
	}
	throw ServerExceptions::QueryMappingExceptions::CannotConvertXml();
}


unique_ptr<string> CreateMethod::getMethodName()
{
	return unique_ptr<string>(new string("create"));
}