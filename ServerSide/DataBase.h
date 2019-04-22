#pragma once
#include <list>
#include "MaterialEntity.h"

using std::list;
using std::pair;

class DataBase
{
	list<pair<string, MaterialEntity*>> TableList;

public:
	DataBase();
	~DataBase();
};

