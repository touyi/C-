#pragma once

/*
* 类属性以及方法的反射基类 如果要反射方法以及属性 需要继承该类 并且注册方法与属性 
* 方法支持虚方法 普通成员方法 不支持重载函数
* 属性通过get 返回属性引用
*/

#include<map>
#include<string>
using std::map;
using std::string;
/*error-type*/
struct Error_Property_Name{};
struct Error_Type_Return {};
struct Error_Function_Name {};

class CProBase
{
public:
	typedef void*(*GetPtr)(CProBase*);
	typedef void* CallFun;
protected:
	map<string, GetPtr> getMap;
	map<string, CallFun> funcMap;
public:
	template<typename T>
	T& get(string pro_name);

	template<typename ReturnType, typename ClassType = CProBase, typename ...Args>
	ReturnType Call(string, Args...);

	virtual void RegisteProperty() = 0;
	CProBase() = default;
	virtual ~CProBase() = default;
};

template<typename T>
T& CProBase::get(string pro_name) {
	if (getMap.count(pro_name)) {
		T* ret = static_cast<T*>(getMap[pro_name](this));
		if (ret == NULL)throw Error_Type_Return();
		return *ret;
	}
	throw Error_Property_Name();
}

template<typename ReturnType, typename ClassType, typename ...Args>
ReturnType CProBase::Call(string func_name, Args ...args)
{
	if (funcMap.count(func_name)) {
		ReturnType(ClassType::*func)(Args...) = *(ReturnType(ClassType::**)(Args...))funcMap[func_name];
		ClassType* _this = static_cast<ClassType*>(this);
		return (_this->*func)(args...);
	}
	throw Error_Function_Name();
}


#define RegistBegin \
virtual void RegisteProperty() {

#define RegistEnd }

#define DeclearProperty(class_type,pro_type,pro_name)\
static void* get##pro_name(CProBase*_this){\
	class_type* tmp = static_cast<class_type*>(_this);\
	return &tmp->pro_name;\
}

#define RegistPro(pro_name)\
getMap.insert(std::pair<string,GetPtr>(#pro_name,get##pro_name));

#define RegistFunction(class_type,func_name)\
static auto func_name##ptr = &class_type::func_name;\
funcMap.insert(std::pair<string, CallFun>(#func_name, &func_name##ptr));




