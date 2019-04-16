#pragma once
#include"jdbc/cppconn/sqlstring.h"
#include "MaterialEntity.h"
#include "EntityAbstract.h"
#include <vector>
#include "boost/any.hpp"

using sql::SQLString;
using std::vector;
using std::string;

	class QueryGenerator
	{
	public:
		QueryGenerator();
		~QueryGenerator();

		SQLString* insert(EntityAbstract &entity);
		SQLString* selectByIndex(EntityAbstract &entity, unsigned int index);
		SQLString* selectAll(EntityAbstract &entity);
		SQLString* selectOrderBy(EntityAbstract &entity, unsigned short columnIndex);
	};