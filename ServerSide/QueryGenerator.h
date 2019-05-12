#pragma once
#include"jdbc/cppconn/sqlstring.h"
#include <memory>
#include <cstring>
#include <vector>
#include "MappingInterface.h"


using sql::SQLString;
using std::vector;
using std::string;
using std::unique_ptr;
using std::shared_ptr;

class DatabaseHandler;

	class QueryGenerator
	{
	private:

		unique_ptr<string> separateWithSymbols(vector<string>& collection, string firstSymbol, string separatingSymbol, string endingSymbol);
		/*unique_ptr<string> entityValuesToQueryPart(EntityInterface& entity);
		unique_ptr<string> entityFieldsToQueryPart(EntityInterface& entity);*/
	public:
		QueryGenerator();
		~QueryGenerator();
		unique_ptr<SQLString> insert(vector<unique_ptr<EntityInterface>> &entityCollection);
		unique_ptr<SQLString> selectByIndex(EntityInterface &entity, unsigned int index);
		unique_ptr<SQLString> selectAll(EntityInterface &entity);
		unique_ptr<SQLString> selectOrderBy(EntityInterface &entity, unsigned short columnIndex);
	};
