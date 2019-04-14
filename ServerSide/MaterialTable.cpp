#include "MaterialTable.h"

std::string IdColumn::getName()				{ return "id"; }

std::string NameColumn::getName()			{ return "name"; }

std::string LambdaColumn::getName()			{ return "lambda"; }

std::string PriceColumn::getName()			{ return "price"; }

std::string TypeOfMaterialColumn::getName() { return "type_of_material"; }

std::string PriceToLambdaColumn::getName()	{ return"price_to_lambda"; }

std::string ProducerColumn::getName()		{ return "producer"; }

std::string LinkColumn::getName()			{ return "link"; }

MaterialTable::MaterialTable()
	:	idColumn(),
		nameColumn(),
		lambdaColumn(),
		priceColumn(),
		typeColumn(),
		priceLambdaColumn(),
		producerColumn(),
		linkColumn(),
		Fields(8)
{
	Fields[0] = &idColumn;
	Fields[1] = &nameColumn;
	Fields[2] = &lambdaColumn;
	Fields[3] = &priceColumn;
	Fields[4] = &typeColumn;
	Fields[5] = &priceLambdaColumn;
	Fields[6] = &producerColumn;
	Fields[7] = &linkColumn;
}

MaterialTable::~MaterialTable()
{
}
