#include "pch.h"
#include "ConnectionHandler.h"
#include "CreateMethodDocument.h"
#include "ReadMethodDocument.h"
#include "SFML/Network.hpp"
#include <cstdlib>
#include <iostream>


using std::string;


int main()
{
	bool run = true;
	ConnectionHandler connectionHandler(54000);
	
		
	while (run)
	{
		cout << "*******************************" << endl;
		cout << "Type one of below numbers and hit ENTER:" << endl << endl;
		cout << "1: insert new record to database" << endl;
		cout << "2: read records from database" << endl;
		cout << "3: disconnect" << endl;

		int choice;
		cin >> choice;

		bool goodChoice = false;
		do
		{
			switch (choice)
			{
			case 1:
				{
					CreateMethodDocument createMethod;
					goodChoice = createMethod.createDatabaseRecord(connectionHandler);
					connectionHandler.waitForResponse(&createMethod);
				}
				break;
			case 2:
				{
					ReadMethodDocument readMethod;
					goodChoice = readMethod.readDatabaseRecord(connectionHandler);
					connectionHandler.waitForResponse(&readMethod);
				}
				break;
			case 3:
					goodChoice = true;
					run = false;
				break;
			}

		} while (!goodChoice);
	}
	return 0;
}
