#pragma once
#include "ConnectionHandler.h"
#include "MethodInterface.h"
#include "pugixml.hpp"
#include <sstream>

using pugi::xml_attribute;
using pugi::xml_document;
using pugi::xml_node;
using std::stringstream;

class ConnectionHandler;

class ReadMethodDocument
	:	public MethodInterface
{
	string printEntity(xml_node& entity);							// returns string that will be printed on screen
	void printEntityTable(xml_node& responseNode);					// prints on console all entities found in response XML document
public:
	ReadMethodDocument();
	~ReadMethodDocument();

	bool readDatabaseRecord(ConnectionHandler& connectionHandler);	// receive all data from server
	void printResponse(string& response) override;					// initializes printing informations on console screen
};

