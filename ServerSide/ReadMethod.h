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
#include <memory>

using std::vector;
using std::unique_ptr;
using std::string;
using sql::SQLString;
using sql::ResultSet;


class Query;
class ResultingQuery;

class ReadMethodMaterials
	: public ReadMethodInterface
{
		QueryGenerator* queryGenerator;
	
public:
	ReadMethodMaterials(QueryGenerator* queryGenerator);
	~ReadMethodMaterials();

	vector<unique_ptr<EntityInterface>> generateEntities(shared_ptr<ResultSet> resultSet) override;	// translates sql::ResultSet to entity
	unique_ptr<Query> generateQuery(DocumentXml& document) override;								
	unique_ptr<string> getMethodName() override;
	bool isResulting() override;																	// returns true if query is resulting
};

