/*
测试使用的类
*/
#include"Factory.h"
#include<iostream>
using namespace std;

class Test :public CProBase {
public:
	int a;
	string str;
	virtual void fun(int a) {
		cout << "Test fun call!! input is " <<  a << endl;
	}
private:
	// 注册
	//DeclearProperty(Test, int, a)
	//DeclearProperty(Test, string, str)
	RegistBegin
		RegistPro(a)
		RegistPro(str)
		RegistFunction(Test, fun)
	RegistEnd
};
REGISTE(Test)

class TestDrive :public Test {
public:
	virtual void fun(int a) {
		cout << "TestDrive fun call!! input is " << a << endl;
	}
};
REGISTE(TestDrive)