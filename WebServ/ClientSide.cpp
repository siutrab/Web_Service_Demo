#include "pch.h"
#include "ConnectionHandler.h"
#include "CreateMethodDocument.h"
#include "SFML/Network.hpp"
#include <iostream>
#include <thread>

int main()
{
	bool run = true;
	ConnectionHandler connectionHandler(54000);
	

	if (connectionHandler.start())
	{
		while (run)
		{
			CreateMethodDocument createDocument;
			createDocument.collectData();
			string* xmlFile = createDocument.generateXml();
			connectionHandler.sendData(*xmlFile);
		}
	}
}

