#include "pch.h"
#include "Server.h"
#include "DatabaseHandler.h"
#include <iostream>

int main()
{
	DatabaseHandler dbHandler;
	dbHandler.connectDatabase();
	Server server(54000);
	std::cin.get();
}
