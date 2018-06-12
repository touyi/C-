#pragma once
#include<map>
#include<string>
using std::map;
using std::string;
/*error-type*/
struct Error_Property_Name{};
struct Error_Type_Return {};

class CProBase
{
public:
	typedef void*(*GetPtr)(CProBase*);
protected:
	map<string, GetPtr> getMap;
public:
	template<typename T>
	T& get(string pro_name) {
		if (getMap.count(pro_name)) {
			T* ret = static_cast<T*>(getMap[pro_name](this));
			if (ret == NULL)throw Error_Type_Return();
			return *ret;
		}
		throw Error_Property_Name();
	}
	virtual void RegisteProperty() = 0;
	CProBase() = default;
	virtual ~CProBase() = default;
};







#define DeclearProperty(class_type,pro_type,pro_name)\
static void* get##pro_name(CProBase*_this){\
	class_type* tmp = static_cast<class_type*>(_this);\
	return &tmp->pro_name;\
}

#define RegisterPro(pro_name)\
getMap.insert(std::pair<string,GetPtr>(#pro_name,get##pro_name));

