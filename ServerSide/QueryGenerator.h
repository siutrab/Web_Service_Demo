#pragma once
#include"jdbc/cppconn/sqlstring.h"
#include "MappingInterface.h"
#include <vector>

using sql::SQLString;
using std::vector;
using std::string;

	class QueryGenerator
	{
	public:
		QueryGenerator();
		~QueryGenerator();

		SQLString* insert(EntityInterface &entity);
		SQLString* selectByIndex(EntityInterface &entity, unsigned int index);
		SQLString* selectAll(EntityInterface &entity);
		SQLString* selectOrderBy(EntityInterface &entity, unsigned short columnIndex);
	};