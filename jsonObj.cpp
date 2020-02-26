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

bool jsonObj::LockCurObj()
{
	return m_json.LockCurObj();
}

void jsonObj::UnlockObj()
{
	return m_json.UnlockObj();
}

void jsonObj::ClearLocks()
{
	return m_json.ClearLocks();
}

jsonObj::~jsonObj(void)
{
}
