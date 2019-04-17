#include "QueryGenerator.h"



QueryGenerator::QueryGenerator()
{
}


QueryGenerator::~QueryGenerator()
{
}


SQLString* QueryGenerator::insert(EntityInterface &entity)
{
	vector<FieldInterface*>* Fields = entity.getFieldsVector();
	string columnsNames;
	string columnsValues;

	unsigned short lastIndex = Fields->size() - 1;

	for (int i = 1; i < lastIndex - 1; i++)		// starts from index 1 because index 0 ("id") is autoincremented primary key in db
	{
		columnsValues += "\"" + *((*Fields)[i]->getValueAsString()) + "\",";
		columnsNames += "`" + *((*Fields)[i]->getColumnName()) + "`,";
	}
	columnsValues += "\"" + *((*Fields)[lastIndex]->getValueAsString()) + "\"";
	columnsNames += "`" + *((*Fields)[lastIndex]->getColumnName()) + "`";

	string Query = "INSERT INTO `" + entity.getTableName() + "`(" + columnsNames + ")VALUES(" + columnsValues + ")";
	std::cout << Query;
	return new sql::SQLString(Query.c_str());
}

//"INSERT INTO `materials`(`id`, `name`, `lambda`, `price`, `type_of_material`, `price_to_lambda`, `producer`, `link`) 
//VALUES (NULL,\"ROCKTON\",0.037, 100, \"wool\", 2700, \"ROCKWOOL\", \"http\")
