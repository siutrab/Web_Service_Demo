#include "pch.h"
#include "ConnectionHandler.h"
#include "CreateMethodDocument.h"
#include "SFML/Network.hpp"
#include <iostream>
#include <thread>

using std::string;

int main()
{
	bool run = true;
	ConnectionHandler connectionHandler(54000);
	

	if (connectionHandler.start())
	{
		string msg(
		"<?xml version=\"1.0\"?>\
					<soap:Envelope>\
						<soap:Body>\
							<request id=\"123456\"/>\
							<table name=\"materials\"/>\
							<method name=\"read\"/>\
						</soap:Body>\
					</soap:Envelope>");

	
		
			connectionHandler.sendData(msg);
		while (run)
		{
			CreateMethodDocument createDocument;
			createDocument.collectData();
			string* xmlFile = createDocument.generateXml();
			connectionHandler.sendData(*xmlFile);
			
		}
	}
}

