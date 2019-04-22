#include "pch.h"
#include "Server.h"
#include "DatabaseHandler.h"
#include <iostream>
#include "QueryGenerator.h"

using std::unique_ptr;

int main()
{
	Server server(54000);
	DatabaseHandler dbHandler;
	float a = 14, b = 142;
	int c = 12;
	std::string st = "eegrh";

	vector<EntityInterface*> vectofMaterials;
	MaterialEntity material(c, a, b, b, st, st, st, st);
	MaterialEntity material2(c, a, a, a, st, st, st, st);
	vectofMaterials.push_back(&material);
	vectofMaterials.push_back(&material2);
	
	QueryGenerator generator(nullptr);
	unique_ptr<SQLString> query = generator.insert(vectofMaterials);
	dbHandler.executeQuery(*query);

	std::cin.get();
}
