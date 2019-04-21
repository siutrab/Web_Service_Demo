#pragma once
#include"jdbc/cppconn/sqlstring.h"
#include "MappingInterface.h"
#include <vector>
#include "DatabaseHandler.h"

using sql::SQLString;
using std::vector;
using std::string;
using std::unique_ptr;

class DatabaseHandler;

	class QueryGenerator
	{
	private:
		DatabaseHandler* databaseHandler;
	public:
		QueryGenerator(DatabaseHandler* pointer);
		~QueryGenerator();
		unique_ptr<SQLString> insert(EntityInterface &entity);
		unique_ptr<SQLString> selectByIndex(EntityInterface &entity, unsigned int index);
		unique_ptr<SQLString> selectAll(EntityInterface &entity);
		unique_ptr<SQLString> selectOrderBy(EntityInterface &entity, unsigned short columnIndex);
	};