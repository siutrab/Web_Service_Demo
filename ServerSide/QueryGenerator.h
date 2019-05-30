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
		// Separates the collection of words with specyfic symbols
		// ex. word1 word2, ---> "word1","word2:LLL
		unique_ptr<string> separateWithSymbols(vector<string>& collection, string firstSymbol, string separatingSymbol, string endingSymbol);
	public:
		QueryGenerator();
		~QueryGenerator();
		unique_ptr<SQLString> insert(vector<unique_ptr<EntityInterface>> &entityCollection);	// Creates INSERT sql query
		unique_ptr<SQLString> selectAll();	// Cretes SELECT * sql query
	};
