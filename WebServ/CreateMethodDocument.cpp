#include "pch.h"
#include "CreateMethodDocument.h"

unsigned int CreateMethodDocument::requestNumber = 0;


CreateMethodDocument::CreateMethodDocument()
	:	document()
{
	requestNumber++;

	xml_node soapEnvelope = document.append_child("soap:Envelope");
	
	xml_node soapBody = soapEnvelope.append_child("soap:Body");
	
	xml_node request = soapBody.append_child("request");
	request.append_attribute("id");
	request.first_attribute().set_value(requestNumber);

	xml_node table = soapBody.append_child("table");
	table.append_attribute("name");
	table.first_attribute().set_value("materials");

	method = soapBody.append_child("method");
	method.append_attribute("name");
	method.first_attribute().set_value("create");

}


CreateMethodDocument::~CreateMethodDocument()
{
}

void CreateMethodDocument::collectData()
{
	/*
		<?xml version=\"1.0\"?>
		<soap:Envelope>
			<soap:Body>
				<request id = \"123456\" />
				<table name = \"materials\"/>
				<method name = \"create\">
					<name> FRONTROCK </name>
					<lambda> 0.034 </lambda>
					<widths>
						<width> 8 </width>
						<width> 10 </width>
						<width> 12 </width>
						<width> 14 </width>
						<width> 16 </width>
					</widths>
					<price> 127 </price>
					<type> wool </type>
					<producer> ROCKWOOL </producer>
					<link> www.rockwool.pl </link>
				</method>
			</soap:Body>
		</soap:Envelope>
	*/

	addNode<string>("name", "What is material name?", method);
	addNode<float>("lambda", "What is material lambda parameter?", method);
	method.append_child("widths");
	addNode<float>("price", "What is materials price?", method);
	addNode<string>("type", "What is materials type? (PIR, XPS, wool etc.)", method);
	addNode<string>("producer", "What is producers name", method);
	addNode<string>("link", "What is link to the producers web page?", method);
	
	initializeWidths();
}

void CreateMethodDocument::initializeWidths()
{
	xml_node widthsNode = method.child("widths");
	cout << "How many sizes are available?" << endl;
	int widthsCount;
	
	while (true)
	{
		cin >> widthsCount;
		if (!cin)
		{
			cout << "Bad argument." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else break;
	}

	for (int i = 0; i < widthsCount; i++)
		addNode<int>("width", "Type width", widthsNode);
}

string* CreateMethodDocument::generateXml()
{
	std::stringstream ss;

	document.print(ss);
	documentXml += ss.str();
	cout << documentXml;

	return &documentXml;
}