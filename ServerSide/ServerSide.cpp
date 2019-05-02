#include "pch.h"
#include "Server.h"
//#include "DatabaseHandler.h"
#include <iostream>
//#include "QueryGenerator.h"

using std::unique_ptr;
using std::string;

int main()
{
	Server server(54000);
	DatabaseHandler dbHandler;
	float a = 14, b = 142;
	int c = 12;
	std::string st = "eegrh";
	unsigned short w = 12;
	unsigned short w2 = 8;
	vector<EntityInterface*> vectofMaterials;
	MaterialEntity material(NULL, a, b, b, w, st, st, st, st);
	MaterialEntity material2(c, a, a, a, w2, st, st, st, st);
	vectofMaterials.push_back(&material);
	vectofMaterials.push_back(&material2);
	
	QueryGenerator generator(nullptr);
//	unique_ptr<SQLString> query = generator.insert(vectofMaterials);
//	dbHandler.executeQuery(*query);

	std::cin.get();
	std::cin.get();
}
