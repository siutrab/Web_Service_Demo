#pragma once
#include "ConnectionHandler.h"

class ConnectionHandler;

class ReadMethodDocument
{
public:
	ReadMethodDocument();
	~ReadMethodDocument();

	bool readDatabaseRecord(ConnectionHandler& connectionHandler);
};

