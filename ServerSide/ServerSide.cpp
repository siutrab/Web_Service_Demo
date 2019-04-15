#include "pch.h"
#include "Server.h"
#include "DatabaseHandler.h"
#include <iostream>
#include "QueryGenerator.h"

int main()
{
	DatabaseHandler dbHandler;
	dbHandler.executeQuery("soub");
	float a = 14, b = 142;
	int c = 12;
	std::string st = "eegrh";
	MaterialEntity material(c, a, b, b, st, st, st, st);
	QueryGenerator generator;
	generator.insert(material);
	//dbHandler.connectDatabase();dbHandler.connectDatabase();dbHandler.connectDatabase();
	Server server(54000);
	std::cin.get();
}
