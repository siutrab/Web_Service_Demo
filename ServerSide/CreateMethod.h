#pragma once
#include "DocumentXml.h"
#include "MethodInterface.h"
#include "EntityInterface.h"
#include "QueryGenerator.h"
#include "MaterialEntity.h"
#include "boost/lexical_cast.hpp"
#include "boost/lexical_cast/bad_lexical_cast.hpp"
#include <memory>
#include <string>
#include <algorithm>


using std::unique_ptr;
using std::string;

class QueryGenerator;
class MaterialEntity;

extern void eraseSpaces(string& str);

class CreateMethodMaterials
	: public CreateMethodInterface
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

	vector<unique_ptr<EntityInterface>> generateEntities();	// Creates entities that coul be esily translated
	bool initializeWidthsList();							// Number of db records depends on how many sizes are avaiable
	bool mapParameters();									// Sets vlues of all parameters of CREATE method

public:
	CreateMethodMaterials(QueryGenerator* queryGenerator);
	~CreateMethodMaterials();
	unique_ptr<Query> generateQuery(DocumentXml& document) override;
	unique_ptr<string> getMethodName() override;
	bool isResulting() override;							// Returns true if query results with some entities

};
