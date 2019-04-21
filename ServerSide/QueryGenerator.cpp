#include "QueryGenerator.h"



QueryGenerator::QueryGenerator(DatabaseHandler* pointer)
	:	databaseHandler(pointer)
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