
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
	/*
	������ : ����Ű��.
	�Ϲ� ������ �Ϲ����� ����.
	��� ���� Ÿ���� ������ Ÿ���� ������ �� ����.
	int ������ �ּҴ� int ������ ������ �����ؾ��Ѵ�.
	�����ʹ� �޸� �ּҸ� ��Ƴ��� �����̱� ������
	x86���� ������ ���� 4byte, x64�� ������ ���� 8byte �� ���´�.

	�����ʹ� �ڱ� ������ �ƹ��� ó���� �� �� ����.
	�ݵ�� �ٸ� ������ �޸� �ּҸ� ������ �־���ϸ�,
	�� �޸� �ּҿ� �����ؼ� ���� ������ �� �ִ�.

	���� : ����Ÿ�� *������;
	*/

	int iNumber = 100;
	// ���� �տ� &�� �ٿ��ָ� �ش� ������ �޸� �ּҰ� �ȴ�.
	int *pNum = &iNumber;

	// �������� �̿��ؼ� ���� �����ų� ����
	// �������� ������ ���� �տ� *�� ���̰ԵǸ� �������� ��
	cout << *pNum << endl;
	*pNum = 1234;

	cout << "iNumber Value : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Address : " << &pNum << endl;

	/*
	�����Ϳ� �迭�� ���� : �迭���� �����ʹ�.
	�迭�� ��ü�� �ش� �迭�� �޸� ������ �ּҸ� �ǹ���
	*/

	int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	cout << "Array Address : " << iArray << endl;
	cout << "Array Address : " << &iArray << endl;

	int *pArray = iArray;

	cout << pArray[2] << endl;

	/*
	������ ���� : +, - ������ �����Ѵ�.
	++, -- ���굵 �����ѵ�, 1�� �����ϰ� �Ǹ� �ܼ��� �޸� �ּҰ��� 1 �����ϴ°��� �ƴ�
	int �������� ���, 1 ���� �� ����Ű�� �ش� ������ Ÿ���� ���� ũ�⸸ŭ �����ϰ� �� (ex, int�� ��� 4 ��ŭ ����)
	*/

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *(pArray + 100) << endl;

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

	// void ������
	// *void ������ �����ϰ� �Ǹ� �� ������ ��� Ÿ���� �޸� �ּҸ� ������ �� ����
	// ��, �������� �Ұ����ϰ� �޸� �ּҸ� ���� ����
	void* pVoid = &iNumber;
	cout << "iNumber Address : " << pVoid << endl;
	//*pVoid = 10;
	int* pConvert = (int*)pVoid;
	*pConvert = 101010;
	cout << iNumber << endl;

	pVoid = &tStudent;
	cout << "tStudent Address : " << pVoid << endl;
	

	return 0;
}