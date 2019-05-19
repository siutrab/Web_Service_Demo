#pragma once
#include "EntityInterface.h"
#include "jdbc/cppconn/sqlstring.h"
#include <memory>
#include <cstring>
#include <vector>


using sql::SQLString;
using std::vector;
using std::string;
using std::unique_ptr;

class DatabaseHandler;

	class QueryGenerator
	{
	private:

		unique_ptr<string> separateWithSymbols(vector<string>& collection, string firstSymbol, string separatingSymbol, string endingSymbol);
	public:
		QueryGenerator();
		~QueryGenerator();
		unique_ptr<SQLString> insert(vector<unique_ptr<EntityInterface>> &entityCollection);
		unique_ptr<SQLString> selectAll();
		unique_ptr<SQLString> selectByIndex(EntityInterface &entity, unsigned int index);
		unique_ptr<SQLString> selectOrderBy(EntityInterface &entity, unsigned short columnIndex);
	};
