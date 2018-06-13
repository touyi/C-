#pragma once

/*
*	反射工厂 通过类名 与 类实例化函数 在工厂注册 通过CreateClass 调用返回指定类型
*/


#include<map>
#include<string>
#include<functional>
#include"ProBase.h"
using std::string;
using std::map;
using std::function;

/*error_type*/
struct Error_Class_Name {};



class CFactory
{
public:
	typedef function<CProBase*()> VoidMethod;
	typedef CProBase* CreateReturnType;
private:
	map<string, VoidMethod> createMap;
public:
	template<typename T>
	T* CreateClass(string className)
	{
		if (createMap.count(className)) {
			T* ret = static_cast<T*>(createMap[className]());
			if (ret == NULL)throw Error_Type_Return();
			ret->RegisteProperty();
			return ret;
		}
		throw Error_Class_Name();
	}
	void RegisteCreatMap(string, VoidMethod);
	static CFactory& GetInstance();
	CFactory() = default;
	~CFactory() = default;
};


// 注册类 用静态变量方式构造注册类信息
class Register {
public:
	Register(string class_name, CFactory::VoidMethod method) {
		CFactory::GetInstance().RegisteCreatMap(class_name, method);
	}
};


template<typename T = CProBase>
T* FactoryCreate(string name) {
	return CFactory::GetInstance().CreateClass<T>(name);
}

// 类注册 需要引入该宏
#define REGISTE(class_name)\
class Register##class_name{\
	public:\
		static CFactory::CreateReturnType Creat##class_name(){\
			return new class_name();\
		}\
		const static Register _register##class_name;\
};\
const Register Register##class_name::_register##class_name(#class_name,Register##class_name::Creat##class_name);
