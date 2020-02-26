#pragma once
#include "jsonObjFunc.h"

class jsonObj
{
public:
	jsonObj(void);
	~jsonObj(void);
public:
	bool CjsonParse(const char* jsonstr);
	jsonObjFunc& operator [](const char* key);
	jsonObjFunc& operator [](int pos);
	jsonObjFunc& LastData(void);
	bool LockCurObj();
	void UnlockObj();
	void ClearLocks();
private:
	jsonObjFunc m_json;
};

