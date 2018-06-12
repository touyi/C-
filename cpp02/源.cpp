#include<iostream>
#include"Factory.h"
using namespace std;
class Test :public CProBase {
public:
	int a;
	string str;
	/*static int& geta(CProBase*_this) {
	Test* tmp = static_cast<Test*>(_this);
		return tmp->a;
	}
	static void seta(CProBase*_this,void* value){
		Test* tmp = static_cast<Test*>(_this);
		tmp->a = static_cast<int>(*value);
	}*/
	DeclearProperty(Test, int, a)
	virtual void RegisteProperty() {
		RegisterPro(a)
		//getMap.insert(std::pair<string, GetPtr>("a", geta)), setMap.insert(std::pair<string, SetPtr>("a", seta));
	}
};

int main() {
	
	system("pause");
	return 0;
}