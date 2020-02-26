#pragma once
#include "cJSON.h"
#include <stack>
enum JsonType
{
	CJSONERR = 0,
	CJSONNULL,
	CJSONINT,
	CJSONSTR
};
class jsonObj;
class jsonObjFunc
{
public:
	friend class jsonObj;
	~jsonObjFunc(void);
private:
	jsonObjFunc(void);
private:
	void InitEdata(void);
	void InitCdata(void);
	void InitMembers(void);
	void FreeMembers(void);
	void ResetPos(void);
	void SetCdata(void);
	void ClearStack(void);
public:
	bool CjsonParse(const char* jsonstr);
	jsonObjFunc& operator [](const char* key);
	jsonObjFunc& operator [](int pos);
	operator const char*() { return c_str; }
	operator int() { return (int)c_int; }
	operator bool() { return c_type != CJSONERR; }
	bool LockCurObj();
	void UnlockObj();
	void ClearLocks();
	
public:
	int c_int;
	const char* c_str;
	enum JsonType c_type;
private:
	cJSON* m_root;
	cJSON* m_pos;
	std::stack<cJSON*> m_objs;
};

