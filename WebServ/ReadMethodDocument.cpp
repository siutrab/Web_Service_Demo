#include "pch.h"
#include "ReadMethodDocument.h"


ReadMethodDocument::ReadMethodDocument()
{	}


ReadMethodDocument::~ReadMethodDocument()
{	}


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


void ReadMethodDocument::printResponse(string& response)
{
	xml_document document;
	pugi::xml_parse_result result = document.load_string(response.c_str());
	if (result)
	{
		xml_node responseNode = document.child("soap:Envelope").child("soap:Body").child("response");
		string id = responseNode.attribute("id").value();
		
		string resultSuccess = responseNode.attribute("result").value();
		if (resultSuccess == "success")
		{
			printEntityTable(responseNode);
			cout << "Request id: " << id << endl;
			cout << "Status: succeed" << endl << endl << endl;
		}
		else
			cout << "Status: fail" << endl;
	}
}

void ReadMethodDocument::printEntityTable(xml_node& responseNode)
{
	int counter = 0;
	stringstream sstream;

	for (xml_node node = responseNode.first_child(); node; node = node.next_sibling())
	{
		sstream << printEntity(node);
		counter++;
	}
	cout << sstream.str() << endl << endl << "Total number of entities: " << counter << endl;
}

string ReadMethodDocument::printEntity(xml_node& entity)
{
	string id, name, lambda, price, width, materialType, priceToLambda, producer, link;

	id = entity.child("id").text().get();
	name = entity.child("name").text().get();
	lambda = entity.child("lambda").text().get();
	price = entity.child("price").text().get();
	width = entity.child("width").text().get();
	materialType = entity.child("type_of_material").text().get();
	priceToLambda = entity.child("price_to_lambda").text().get();
	producer = entity.child("producer").text().get();
	link = entity.child("link").text().get();
	
	stringstream sstream;

	sstream << endl << endl << "*******************************" << endl << "ENTITY:" << endl
		<< "\t" << "id:				" << id << endl
		<< "\t" << "name:				" << name << endl
		<< "\t" << "lambda parameter:		" << lambda << endl
		<< "\t" << "price:				" << price << "pln" << endl
		<< "\t" << "width:				" << width << "cm" << endl
		<< "\t" << "material:			" << materialType << endl
		<< "\t" << "price to lambda factor:		" << priceToLambda << endl
		<< "\t" << "producer:			" << producer << endl
		<< "\t" << "link:				" << link << endl;
	return sstream.str();
}
