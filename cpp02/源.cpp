#include<iostream>
#include"Factory.h"
using namespace std;


int main() {
	

	CProBase* ptr = FactoryCreate("Test"); // 根据类名创建类型
	int c = 5;
	ptr->set<string*>("str","666"); // 反射获取Test对象的str (string)属性
	ptr->set("a",15);         // 反射设置Test对象的a (int)属性
	cout << ptr->get<string>("str") << " " << ptr->get<int>("a") << endl;  // 输出：666 15

	ptr->Call<void>("fun",123);   // 反射调用Test对象的fun方法 返回为void 传入参数 123
	delete ptr;

	// 支持虚方法的调用
	ptr = FactoryCreate("TestDrive");  // TestDrive继承于 Test 并且重写了虚方法 fun
	ptr->Call<void>("fun", 123);       // 输出：drive 调用为子类方法
	system("pause");
	return 0;
}