#pragma once

/*
*	���乤�� ͨ������ �� ��ʵ�������� �ڹ���ע�� ͨ��CreateClass ���÷���ָ������
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


// ע���� �þ�̬������ʽ����ע������Ϣ
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

// ��ע�� ��Ҫ����ú�
#define REGISTE(class_name)\
class Register##class_name{\
	public:\
		static CFactory::CreateReturnType Creat##class_name(){\
			return new class_name();\
		}\
		const static Register _register##class_name;\
};\
const Register Register##class_name::_register##class_name(#class_name,Register##class_name::Creat##class_name);
