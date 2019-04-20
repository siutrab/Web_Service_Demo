#pragma once
#include"jdbc/cppconn/sqlstring.h"
#include "MappingInterface.h"
#include <vector>

using sql::SQLString;
using std::vector;
using std::string;
using std::unique_ptr;

	class QueryGenerator
	{
	public:
		QueryGenerator();
		~QueryGenerator();

		unique_ptr<SQLString> insert(EntityInterface &entity);
		unique_ptr<SQLString> selectByIndex(EntityInterface &entity, unsigned int index);
		unique_ptr<SQLString> selectAll(EntityInterface &entity);
		unique_ptr<SQLString> selectOrderBy(EntityInterface &entity, unsigned short columnIndex);
	};