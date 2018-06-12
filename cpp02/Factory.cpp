#include "Factory.h"


void * CFactory::CreateClass(string className)
{
	if (createMap.count(className)) {
		return createMap[className]();
	}
	throw Error_Class_Name();
}

void CFactory::RegisteCreatMap(string className, CFactory::VoidMethod method)
{
	createMap.insert(std::pair<string, CFactory::VoidMethod>(className, method));
}

CFactory& CFactory::GetInstance()
{
	static CFactory _instance;
	return _instance;
}


