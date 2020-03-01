#include "jsonObjFunc.h"

jsonObjFunc::jsonObjFunc(void)
{
	InitMembers();
}

void jsonObjFunc::InitEdata(void)
{
	c_int = 0;
	c_str = NULL;
	c_type = CJSONERR;
}

void jsonObjFunc::InitCdata(void)
{
	c_int = 0;
	c_str = NULL;
	c_type = CJSONNULL;
}

void jsonObjFunc::InitMembers(void)
{
	m_root = NULL;
	m_pos = NULL;
	InitCdata();
}

void jsonObjFunc::FreeMembers(void)
{
	if (m_root)
		cJSON_free(m_root);
	while (!m_arrs.empty())m_arrs.pop();
	InitMembers();
}

void jsonObjFunc::ResetPos(void)
{
	m_pos = m_root;
}

void jsonObjFunc::SetCdata(void)
{
	if (m_pos != NULL) {
		if (m_pos->type == cJSON_String) {
			c_str = m_pos->valuestring;
			c_int = 0;
			c_type = CJSONSTR;
		} else if (m_pos->type == cJSON_Number) {
			c_str = NULL;
			c_int = m_pos->valueint;
			c_type = CJSONINT;
		} else {
			InitCdata();
		}
	}
}

jsonObjFunc::~jsonObjFunc(void)
{
	FreeMembers();
}

bool jsonObjFunc::CjsonParse(const char * jsonstr)
{
	FreeMembers();
	return ((m_pos = m_root = cJSON_Parse(jsonstr)) != NULL);
}

jsonObjFunc& jsonObjFunc::operator[](const char * key)
{
	cJSON* tmp = cJSON_GetObjectItem(m_pos, key);
	if (tmp == NULL) {
		InitEdata();
	} else {
		m_pos = tmp;
		SetCdata();
	}
	return *this;
}

jsonObjFunc& jsonObjFunc::operator[](int pos)
{
	if (!m_arrs.empty())m_pos = m_arrs.top();
	if (m_pos == NULL || m_pos->type != cJSON_Array || cJSON_GetArraySize(m_pos) <= pos){
		InitEdata();
	} else {
		cJSON* tmp = cJSON_GetArrayItem(m_pos, pos);
		if (tmp == NULL) {
			InitEdata();
		} else {
			m_pos = tmp;
			SetCdata();
		}
	}
	return *this;
}

bool jsonObjFunc::PushArrObj()
{
	if (m_pos != NULL && m_pos->type == cJSON_Array) {
		m_arrs.push(m_pos);
		return true;
	}
	return false;
}

void jsonObjFunc::PopArrObj()
{
	if (!m_arrs.empty()){
		m_arrs.pop();
	}
}
