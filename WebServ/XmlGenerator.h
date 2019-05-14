#pragma once
#include "XmlTag.h"
#include <iostream>

using std::string;

class XmlGenerator
{
	const string openingTag = "<? xml version=\"1.0\"?><soap:Envelope><soap:Body>";
	const string closeingTag = "</soap:Body></soap:Envelope>";

	const string tableTag = "<table name=\"materials\"/>";
	const string createMethodName = "<method name = \"create\">";

	string requestTag(unsigned int id);
	
	string tableName(string& name);
	string methodName();
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
public:
	XmlGenerator();
	~XmlGenerator();
};

