#pragma once
#include<map>
#include<string>
#include<functional>
using std::string;
using std::map;
using std::function;

/*error_type*/
struct Error_Class_Name {};

class CFactory
{
public:
	typedef function<void*()> VoidMethod;
private:
	map<string, VoidMethod> createMap;
public:
	void* CreateClass(string);
	void RegisteCreatMap(string, VoidMethod);
	static CFactory& GetInstance();
	CFactory() = default;
	~CFactory() = default;
};

class Register {
public:
	Register(string class_name, CFactory::VoidMethod method) {
		CFactory::GetInstance().RegisteCreatMap(class_name, method);
	}
};
#define REGISTE(class_name)\
class Register##class_name{\
	public:\
		static void* Creat##class_name(){\
			return new class_name();\
		}\
		const static Register _register##class_name;\
};\
const Register Register##class_name::_register##class_name(#class_name,Register##class_name::Creat##class_name);


