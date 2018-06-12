#include "ProBase.h"



void CProBase::set(string pro_name,void*value)
{
	if (setMap.count(pro_name)) {
		setMap[pro_name](this, value);
	}
	throw Error_Property_Name();
}

void * CProBase::get(string pro_name)
{
	if (getMap.count(pro_name)) {
		return getMap[pro_name](this);
	}
	throw Error_Property_Name();
}

CProBase::CProBase()
{
}


CProBase::~CProBase()
{
}
