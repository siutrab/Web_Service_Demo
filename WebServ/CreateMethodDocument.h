#pragma once
#include "ConnectionHandler.h"
#include "MethodInterface.h"
#include "pugixml.hpp"
#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using pugi::xml_node;
using pugi::xml_document;

class ConnectionHandler;

class CreateMethodDocument
	: public MethodInterface
{
	ConnectionHandler* connectionHandler;

		xml_document document;
		xml_node method;
		string documentXml = "<?xml version=\"1.0\"?>\n";
	
	template<typename T>
	void addNode(string name, string message, xml_node& node)
	{
		T value;
		cout << message << endl;
		while (true)
		{
			cin >> value;
			if (!cin)
			{
				cout << "Bad argument." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else break;
		}

		std::stringstream ss;
		ss << value;
		string stringValue = ss.str();
		node.append_child(name.c_str()).text().set(stringValue.c_str());
	}

	void collectData();				// gets data from user and initializes the xml tree structure that could be then turned to xml document
	string* generateXml();			// returns pointer to generted xml;
	void initializeWidths();		// collects sizes of materials (widths) from user
	
public:
	CreateMethodDocument();
	~CreateMethodDocument();
	void printResponse(string& response) override;						//returns true if request status is succeed
	bool createDatabaseRecord(ConnectionHandler& connectionHandler);	// collects data and sends it to server as an XML
};

