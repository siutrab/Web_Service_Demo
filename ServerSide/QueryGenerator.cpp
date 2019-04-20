#include "QueryGenerator.h"



QueryGenerator::QueryGenerator()
{
}


QueryGenerator::~QueryGenerator()
{
}


unique_ptr<SQLString> QueryGenerator::insert(EntityInterface &entity)
{
	vector<unique_ptr<FieldInterface>>* Fields = entity.getFieldsVector();
	string columnsNames;
	string columnsValues;

	size_t lastIndex = Fields->size() - 1;

	for (size_t i = 1; i < lastIndex; i++)		// starts from index 1 because index 0 ("id") is autoincremented primary key in db
	{
		columnsValues += "\"" + *((*Fields)[i]->getValueAsString()) + "\",";
		columnsNames += "`" + *((*Fields)[i]->getColumnName()) + "`,";
	}
	columnsValues += "\"" + *((*Fields)[lastIndex]->getValueAsString()) + "\"";
	columnsNames += "`" + *((*Fields)[lastIndex]->getColumnName()) + "`";

	string Query = "INSERT INTO `" + entity.getTableName() + "`(" + columnsNames + ")VALUES(" + columnsValues + ")";
	std::cout << Query << std::endl;
	return unique_ptr<SQLString>(new sql::SQLString(Query.c_str()));
}

//"INSERT INTO `materials`(`id`, `name`, `lambda`, `price`, `type_of_material`, `price_to_lambda`, `producer`, `link`) 
//VALUES (NULL,\"ROCKTON\",0.037, 100, \"wool\", 2700, \"ROCKWOOL\", \"http\")

//INSERT INTO `materials`(`name`, `lambda`, `price`, `type_of_material`, `price_to_lambda`, `producer`, `link`) 
//VALUES("aaa", "14.00000", "3", "value-4", "209.1245", "grh", "erethrjytukvalue-7")
