#include<iostream>
#include"Factory.h"
using namespace std;
class Test {
public:
	int a;
	
};
REGISTE(Test);
int f2(int n) {
	cout << "ok" << endl;
	return n;
}
template<typename ...Args>
int fun(Args...args) {
	function<int()> t = std::bind(f2, args...);
	return t();
}


int main() {
	cout << fun(11);
	system("pause");
	return 0;
}