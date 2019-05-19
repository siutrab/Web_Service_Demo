#include "pch.h"
#include "ReadMethodDocument.h"


ReadMethodDocument::ReadMethodDocument()
{
}


ReadMethodDocument::~ReadMethodDocument()
{
}

bool ReadMethodDocument::readDatabaseRecord(ConnectionHandler& connectionHandler)
{
	string msgFirsPart(
		"<?xml version=\"1.0\"?>\
			<soap:Envelope>\
				<soap:Body>\
					<request id=\"");
	
	string msgSecondPart("\"/>\
					<table name=\"materials\"/>\
					<method name=\"read\"/>\
				</soap:Body>\
			</soap:Envelope>");

	string fullMessage = msgFirsPart + std::to_string(ConnectionHandler::getRequestNumber()) + msgSecondPart;
	
	return connectionHandler.sendData(fullMessage);
}
