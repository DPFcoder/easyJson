#include "jsonObj.h"

jsonObj::jsonObj(void)
{
}

bool jsonObj::CjsonParse(const char * jsonstr)
{
	return m_json.CjsonParse(jsonstr);
}

jsonObjFunc & jsonObj::operator[](const char * key)
{
	m_json.ResetPos();
	return m_json[key];
}

jsonObjFunc & jsonObj::operator[](int pos)
{
	m_json.ResetPos();
	return m_json[pos];
}

jsonObjFunc & jsonObj::LastData(void)
{
	return m_json;
}

bool jsonObj::PushArrObj()
{
	return m_json.PushArrObj();
}

void jsonObj::PopArrObj()
{
	return m_json.PopArrObj();
}

jsonObj::~jsonObj(void)
{
}
