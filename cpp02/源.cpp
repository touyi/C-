#include<iostream>
#include"Factory.h"
using namespace std;


int main() {
	

	CProBase* ptr = FactoryCreate("Test"); // ����������������
	int c = 5;
	ptr->set<string*>("str","666"); // �����ȡTest�����str (string)����
	ptr->set("a",15);         // ��������Test�����a (int)����
	cout << ptr->get<string>("str") << " " << ptr->get<int>("a") << endl;  // �����666 15

	ptr->Call<void>("fun",123);   // �������Test�����fun���� ����Ϊvoid ������� 123
	delete ptr;

	// ֧���鷽���ĵ���
	ptr = FactoryCreate("TestDrive");  // TestDrive�̳��� Test ������д���鷽�� fun
	ptr->Call<void>("fun", 123);       // �����drive ����Ϊ���෽��
	system("pause");
	return 0;
}