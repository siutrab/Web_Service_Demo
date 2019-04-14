#include "QueryGenerator.h"



QueryGenerator::QueryGenerator()
{
}


QueryGenerator::~QueryGenerator()
{
}


sql::SQLString* QueryGenerator::create(EntityAbstract &entity)
{
	std::vector<ColumnAbstract*>* Fields = entity.getVectorFields();
	std::string columnsNames;
	std::string columnsValues = "NULL,";

	unsigned short lastIndex = entity.getFieldsNumber() - 1;

	for (int i = 1; i < lastIndex - 1; i++)
	{
		columnsValues += "\"" + (*Fields)[i]->getValueAsString() + "\",";

	}
	columnsValues += "\"" + (*Fields)[lastIndex]->getValueAsString() + "\"";
	for (int i = 0; i < lastIndex - 1; i++)
	{
		columnsNames += "`" + (*Fields)[i]->getName() + "`,";
	}
	columnsNames += "`" + (*Fields)[lastIndex]->getName() + "`";

	std::string Query = "INSERT INTO `" + entity.getTableName() + "`(" + columnsValues + ")VALUES(" + columnsValues + ")";
	std::cout << Query << std::endl;
	return new sql::SQLString(Query);
}

//"INSERT INTO `materials`(`id`, `name`, `lambda`, `price`, `type_of_material`, `price_to_lambda`, `producer`, `link`) 
//VALUES (NULL,\"ROCKTON\",0.037, 100, \"wool\", 2700, \"ROCKWOOL\", \"http\")
