#pragma once
#include<map>
#include<string>
using std::map;
using std::string;
/*error-type*/
struct Error_Property_Name{};

class CProBase
{
public:
	typedef void*(*GetPtr)(CProBase*);
	typedef void(*SetPtr)(CProBase*,void*);
protected:
	map<string, GetPtr> getMap;
	map<string, SetPtr> setMap;
public:
	void set(string,void*value);
	void*get(string);
	virtual void RegisteProperty() = 0;
	CProBase();
	virtual ~CProBase();
};

#define DeclearProperty(class_type,pro_type,pro_name)\
static void* get##pro_name(CProBase*_this){\
	class_type* tmp = static_cast<class_type*>(_this);\
	return &tmp->pro_name;\
}\
static void set##pro_name(CProBase*_this,void* value){\
	class_type* tmp = static_cast<class_type*>(_this);\
	tmp->pro_name = *(static_cast<pro_type*>(value));\
}

#define RegisterPro(pro_name)\
getMap.insert(std::pair<string,GetPtr>(#pro_name,get##pro_name)),setMap.insert(std::pair<string,SetPtr>(#pro_name,set##pro_name));

