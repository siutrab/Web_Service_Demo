#include "pch.h"
#include "ConnectionHandler.h"
#include "CreateMethodDocument.h"
#include "ReadMethodDocument.h"
#include "SFML/Network.hpp"
#include <iostream>
#include <thread>
#include <cstdlib>

using std::string;


int main()
{
	bool run = true;
	ConnectionHandler connectionHandler(54000);
	

	if (connectionHandler.start())
	{
		/*string msg(
		"<?xml version=\"1.0\"?>\
					<soap:Envelope>\
						<soap:Body>\
							<request id=\"123456\"/>\
							<table name=\"materials\"/>\
							<method name=\"read\"/>\
						</soap:Body>\
					</soap:Envelope>");

	
		
			connectionHandler.sendData(msg);*/
		
		while (run)
		{
			connectionHandler.printResponseMessages();

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
					}
					break;
				case 2:
					{
						ReadMethodDocument readMethod;
						goodChoice = readMethod.readDatabaseRecord(connectionHandler);
					}
					break;
				case 3:
						goodChoice = connectionHandler.stop();
						run = false;
					break;
				}
			
				bool printed = false;
				do
				{
					printed = connectionHandler.printResponseMessages();
				} while (!printed);
				

			} while (!goodChoice);
			
				

		}
	}
}
//
//void menuFunction()
//{
//	cout << "1: insert new record to database" << endl;
//	cout << "2: read records from database" << endl;
//	cout << "3: disconnect" << endl;
//	
//	int choice;
//	cin >> choice;
//
//	bool goodChoice = false;
//	do
//	{
//		
//	switch (choice)
//		{
//		case 1:
//			createDatabaseRecord();
//			break;
//		}
//	} while (!goodChoice);
//	
//}
////
//bool createDatabaseRecord(ConnectionHandler& connectionHandler)
//{
//	CreateMethodDocument createDocument;
//	createDocument.collectData();
//	string* xmlFile = createDocument.generateXml();
//	connectionHandler.sendData(*xmlFile);
//
//	return true;
//}

