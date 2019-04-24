#include "MaterialTable.h"


//unique_ptr<MaterialEntity> MaterialTable::createEntity(valueVector &initialValues)
//{
//	unsigned short vectorLength = initialValues.size();
//	for (size_t i = 0; i < vectorLength; i++)
//	{
//
//	}
//}

MaterialTable::MaterialTable()
{

}

MaterialTable::~MaterialTable()
{}

bool MaterialTable::isNonResultMethod(string& methodName)
{
	if (methodName == "addMaterial") return true;
	else return false;
}
//
//string a = "			<name> FRONTROCK < / name>							\
//						<lambda> 0.034 < / lambda>							\
//						< widths number = \"5\">							\
//							<width> 8 </width>								\
//							<width> 10 </width>								\
//							<width> 12 </width>								\
//							<width> 14 </width>								\
//							<width> 16 </width>								\
//						</widths>											\
//						<price> 0.034 </price>								\
//						<type> wool </type>									\
//						<producer> ROCKWOOL </producer>						\
//						<link> www.rockwool.pl </link>";