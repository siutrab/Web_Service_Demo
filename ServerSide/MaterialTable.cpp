#include "MaterialTable.h"

std::string IdColumn::getName()				{ return "id"; }
std::string IdColumn::getValueAsString() { return  std::to_string(value); }
unsigned int IdColumn::getValue() { return value; }

std::string NameColumn::getName()			{ return "name"; }
std::string NameColumn::getValueAsString() { return value; }
std::string NameColumn::getValue() { return value; }

std::string LambdaColumn::getName()			{ return "lambda"; }
std::string LambdaColumn::getValueAsString() { return std::to_string(value); }
float LambdaColumn::getValue() { return value; }

std::string PriceColumn::getName()			{ return "price"; }
std::string PriceColumn::getValueAsString() { return std::to_string(value); }
float PriceColumn::getValue() { return value; }

std::string TypeOfMaterialColumn::getName() { return "type_of_material"; }
std::string TypeOfMaterialColumn::getValueAsString() { return value; }
std::string TypeOfMaterialColumn::getValue() { return value; }

std::string PriceToLambdaColumn::getName()	{ return"price_to_lambda"; }
std::string PriceToLambdaColumn::getValueAsString() { return std::to_string(value); }
float PriceToLambdaColumn::getValue() { return value; }

std::string ProducerColumn::getName()		{ return "producer"; }
std::string ProducerColumn::getValueAsString() { return value; }
std::string ProducerColumn::getValue() { return value; }

std::string LinkColumn::getName()			{ return "link"; }
std::string LinkColumn::getValueAsString() { return value; }
std::string LinkColumn::getValue() { return value; }

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

std::vector<ColumnAbstract*>* MaterialTable::getFields() { return &Fields; }