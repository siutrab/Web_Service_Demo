#include "pch.h"
#include "Server.h"
#include "DatabaseHandler.h"
#include <iostream>
#include "QueryGenerator.h"

using std::unique_ptr;

int main()
{
	Server server(54000);
	//DatabaseHandler dbHandler;
	float a = 14, b = 142;
	int c = 12;
	std::string st = "eegrh";
	MaterialEntity material(c, a, b, b, st, st, st, st);
	//QueryGenerator generator;
	//unique_ptr<SQLString> query = generator.insert(material);
	//dbHandler.executeQuery(*query);

	std::cin.get();
}
