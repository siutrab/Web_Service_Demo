#pragma once
#include "XmlTag.h"
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class CreqteMethodMapper
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
	const string tableTag = "<table name=\"materials\"/>";
	const string createMethodOpen = "<method name=\"create\">";
	const string createMethodClose = "</method>";

	Tag name = Tag(string("name"));
	Tag lambda = Tag(string("lambda"));
	Tag widths = Tag(string("widths"));
	Tag price = Tag(string("price"));
	Tag type = Tag(string("type"));
	Tag producer = Tag(string("producer"));
	Tag link = Tag(string("link"));

	vector<Tag>widthsVector;

	void setTag(Tag& tag, string message);
	void setWidths();
public:
	CreqteMethodMapper();
	~CreqteMethodMapper();

	void collectData();
	string generateXml();
};

