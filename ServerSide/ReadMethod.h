#pragma once
#include "Query.h"
#include "MethodInterface.h"
#include "QueryGenerator.h"
#include "ExceptionsSystem.h"
#include "MaterialEntity.h"
#include "jdbc/cppconn/resultset.h"
#include "jdbc/cppconn/sqlstring.h"
#include "jdbc/mysql_error.h"

#include <vector>

using std::vector;
using std::string;
using sql::SQLString;


class Query;
class ResultingQuery;

class ReadMethodMaterials
	: public ReadMethodInterface
{
		QueryGenerator* queryGenerator;
	
public:
	ReadMethodMaterials(QueryGenerator* queryGenerator);
	~ReadMethodMaterials();

	vector<unique_ptr<EntityInterface>> generateEntities(ResultSet& resultSet) override;
	unique_ptr<Query> generateQuery(DocumentXml& document) override;
	unique_ptr<string> getMethodName() override;
	bool isResulting() override;
};

