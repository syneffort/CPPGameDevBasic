
#include <iostream>

using namespace std;

int g_iNum = 0;

int Sum(int a, int b)
{
	return a + b;
}

void OutputText()
{
	cout << "OutputText Function!" << endl;
}

void OutputNumber(int iNumber)
{
	cout << "Number : " << iNumber << endl;
}

// �Լ� ���� ������ �Լ��� ���������� stack�� �Ҵ��
void ChangeNumber(int iNumber)
{
	iNumber = 9999;
}

// call by address
void ChangeNumber(int *iNumber)
{
	*iNumber = 9999;
}

void Ouput(int iNum1, int iNum2 = 10)
{
	cout << iNum1 << endl;
	cout << iNum2 << endl;
}

int main()
{
	cout << Sum(10, 20) << endl;

	OutputText();

	OutputNumber(Sum(123, 456));

	// ���� ������ �޸� ���� �� stack�� �Ҵ��
	int iNumber = 0;
	ChangeNumber(iNumber);
	OutputNumber(iNumber);

	ChangeNumber(g_iNum);
	OutputNumber(g_iNum);

	ChangeNumber(&iNumber);
	ChangeNumber(&g_iNum);
	OutputNumber(iNumber);
	OutputNumber(g_iNum);

	Ouput(10);

	return 0;
}