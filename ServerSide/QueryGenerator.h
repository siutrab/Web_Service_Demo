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

		sql::SQLString* create(EntityAbstract &entity);
	};