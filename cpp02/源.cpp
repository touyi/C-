#include<iostream>
#include"Factory.h"
using namespace std;
#define TT(x)/

class Test :public CProBase {
public:
	int a;
	string str;
private:
	DeclearProperty(Test, int, a)
	DeclearProperty(Test, string, str)
	virtual void RegisteProperty() {
		RegisterPro(a)
		RegisterPro(str)
	}
};
REGISTE(Test)

int main() {
	CProBase* ba =FactoryCreate<CProBase>("Test");
	int c = 5;
	ba->get<string>("str") = "666";
	ba->get<int>("a") = 15;
	cout << ba->get<string>("str") << " " << ba->get<int>("a");
	system("pause");
	return 0;
}