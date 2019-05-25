#pragma once
#include "Content.h"
#include "EntityInterface.h"
#include "MethodInterface.h"
#include "jdbc/cppconn/resultset.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;
using sql::ResultSet;

class EntityInterface;

class ResultSetContent
	:	public Content<shared_ptr<ResultSet>>
{
	ReadMethodInterface* method;
public:
	ResultSetContent(shared_ptr<ResultSet>& entityVector, ReadMethodInterface* methodPtr);
	~ResultSetContent();
	ReadMethodInterface* getMethod();
	//void setMethod(ReadMethodInterface* methodPtr);
};

