
#include <iostream>

using namespace std;

struct _tagStudent
{
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main()
{
	// ���� ������
	char *pText = "�׽�Ʈ ���ڿ�";

	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "���ڿ�";
	cout << pText << " : " << (int*)pText << endl;

	pText = "���ڿ�2";
	cout << pText << " : " << (int*)pText << endl;

	pText = "���ڿ�2";
	cout << pText << " : " << (int*)pText << endl;

	char *pText2 = "���ڿ�2";
	cout << pText2 << " : " << (int*)pText2 << endl;

	char str[8] = "���ڿ�2";
	cout << str << endl;
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl;

	// ����ü ������
	// ������ �켱������ ���� * ���� . �� �켱��
	_tagStudent tStudent = {};
	tStudent.iKor = 100;

	_tagStudent *pStudent = &tStudent;
	(*pStudent).iKor = 50;
	// �޸� �ּ� -> �� �̿��� ����� ���� ����
	pStudent -> iKor = 80; 
	cout << tStudent.iKor << endl;

	return 0;
}