#include "QueryGenerator.h"



QueryGenerator::QueryGenerator()
{
}


QueryGenerator::~QueryGenerator()
{
}


sql::SQLString* QueryGenerator::create(EntityAbstract &entity)
{
	std::string columnsNames;
	std::string values;
	std::string singleValue;
	std::vector<ColumnAbstract*>* fieldVector = entity.getVectorFields();
	unsigned int vectorLastIndex = fieldVector->size() - 1;
	
	columnsNames += "`NULL`,";

	singleValue = boost::any_cast<std::string>((*fieldVector)[0]->value);
	values += ("\"" + singleValue + "\",");

	for (int i = 1; i < vectorLastIndex - 1; ++i)		// last iteration is omitted because of , (comma sign) at the end of each string
	{
		columnsNames += ("`" + (*fieldVector)[i]->getName() + "`,");

		singleValue = boost::any_cast<std::string>((*fieldVector)[i]->value);
		values += ("\"" + singleValue + "\",");
	}
	columnsNames += ("`" + (*fieldVector)[vectorLastIndex]->getName() + "`");

	singleValue = boost::any_cast<std::string>((*fieldVector)[vectorLastIndex]->value);
	values += ("\"" + singleValue + "\"");

	std::string result;
	result += "INSERT INTO `" + columnsNames + ") VALUES (" + singleValue + ")";
	std::cout << result << std::endl;
	return new sql::SQLString(result);
}

//"INSERT INTO `materials`(`id`, `name`, `lambda`, `price`, `type_of_material`, `price_to_lambda`, `producer`, `link`) 
//VALUES (NULL,\"ROCKTON\",0.037, 100, \"wool\", 2700, \"ROCKWOOL\", \"http\")
