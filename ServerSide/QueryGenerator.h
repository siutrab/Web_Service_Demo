#pragma once
#include"jdbc/cppconn/sqlstring.h"
#include "MaterialEntity.h"
#include "EntityAbstract.h"
#include <vector>
#include "boost/any.hpp"

	class QueryGenerator
	{
	public:
		QueryGenerator();
		~QueryGenerator();

		sql::SQLString* insert(EntityAbstract &entity);
		sql::SQLString* selectByIndex(EntityAbstract &entity, unsigned int index);
		sql::SQLString* selectAll(EntityAbstract &entity);
		sql::SQLString* selectOrderBy(EntityAbstract &entity, unsigned short columnIndex);
	};