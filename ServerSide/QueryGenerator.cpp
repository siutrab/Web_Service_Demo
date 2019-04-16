#include "QueryGenerator.h"



QueryGenerator::QueryGenerator()
{
}


QueryGenerator::~QueryGenerator()
{
}


SQLString* QueryGenerator::insert(EntityAbstract &entity)
{
	vector<ColumnAbstract*>* Fields = entity.getVectorFields();
	string columnsNames;
	string columnsValues;

	unsigned short lastIndex = entity.getFieldsNumber() - 1;

	for (int i = 1; i < lastIndex - 1; i++)		// starts from index 1 because index 0 ("id") is autoincremented primary key in db
	{
		columnsValues += "\"" + (*Fields)[i]->getValueAsString() + "\",";
		columnsNames += "`" + (*Fields)[i]->getName() + "`,";
	}
	columnsValues += "\"" + (*Fields)[lastIndex]->getValueAsString() + "\"";
	columnsNames += "`" + (*Fields)[lastIndex]->getName() + "`";

	string Query = "INSERT INTO `" + entity.getTableName() + "`(" + columnsNames + ")VALUES(" + columnsValues + ")";
	return new sql::SQLString(Query.c_str());
}

//"INSERT INTO `materials`(`id`, `name`, `lambda`, `price`, `type_of_material`, `price_to_lambda`, `producer`, `link`) 
//VALUES (NULL,\"ROCKTON\",0.037, 100, \"wool\", 2700, \"ROCKWOOL\", \"http\")
