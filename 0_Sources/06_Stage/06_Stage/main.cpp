
#include <iostream>

using namespace std;

#define NAME_SIZE 32

struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main()
{
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	tStudent.iKor = 100;
	
	// ���ڿ��� �迭�� ����
	strcpy_s(tStudent.strName, "Springfield");
	// ���ڿ��� ���̱�
	strcat_s(tStudent.strName, " William");
	// ���ڿ� ��
	strcpy_s(tStudent.strName, "ȫ�浿");
	cout << "���� �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	cin >> strName;
	if (strcmp(tStudent.strName, strName) == 0) // 0�� �� ���� ���ڿ�
	{
		cout << "�л��� ã�ҽ��ϴ�." << endl;
	}
	else
		cout << "ã�� �л��� �����ϴ�." << endl;

	cout << "�̸� ����" << strlen(tStudent.strName) << endl;

	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�й� : " << tStudent.iNumber << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng << endl;
	cout << "���� : " << tStudent.iMath << endl;
	cout << "���� : " << tStudent.iTotal << endl;
	cout << "��� : " << tStudent.fAvg << endl;

	return 0;
}