
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	const int iAttack = 0x00000001;		//	1
	const int iArmor = 0x00000002;		//	10
	const int iHP = 0x00000004;			//	100
	const int iMP = 0x00000008;			//	1000
	const int iCritical = 0x00000010;	//	10000

	// 1 = 001 | 100 = 101 = 00101 | 10000 = 10101
	int iBuf = iAttack | iHP | iCritical;

	// ������ ����� : �����ڸ� �ٿ��� ���
	// 10101 ^ 00100 = 10001
	iBuf ^= iHP;

	// 10001 ^ 00100 = 10101
	iBuf ^= iHP;

	// 10101 & 00001 = 00001
	cout << "Attack : " << (iBuf & iAttack) << endl;
	cout << "Aromor : " << (iBuf & iArmor) << endl;
	cout << "HP : " << (iBuf & iHP) << endl;
	cout << "MP : " << (iBuf & iMP) << endl;
	cout << "Critical : " << (iBuf & iCritical) << endl;

	/*
	����Ʈ ������ : <<, >> 
	������ ������ ���� ����
	20 << 2 = 20 * 4 = 80
	20 << 3 = 20 * 8 = 160
	20 << 4 = 20 * 16 = 320
	10100 => 1010000
	10100 => 10100000 
	10100 => 101000000

	20 >> 2 = 20 / 4 = 5
	20 >> 3 = 20 / 8 = 2
	20 >> 4 = 20 / 16 = 1
	10100 => 101
	10100 => 10
	10100 => 1

	*/

	// 32��Ʈ int 16��Ʈ �� ������ ���
	int iHigh = 187;
	int iLow = 13560;

	// ���� 16��Ʈ�� �� �Ҵ�
	int iNumber = iHigh;
	iNumber << 16;
	
	// ���� 16��Ʈ�� �� �Ҵ�
	iNumber |= iLow;

	// High �� ���
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	// if �б⹮
	if (iBuf & iAttack)
		cout << "Attack ������ �ֽ��ϴ�." << endl;
	
	if (iBuf & iArmor)
		cout << "Armor ������ �ֽ��ϴ�." << endl;

	if (iBuf & iHP)
		cout << "HP ������ �ֽ��ϴ�." << endl;

	if (iBuf & iMP)
		cout << "MP ������ �ֽ��ϴ�." << endl;

	if (iBuf & iCritical)
		cout << "Critcal ������ �ֽ��ϴ�." << endl;

	// ���� �߻�
	srand((unsigned int)time(0));

	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() % 101 << endl;
	cout << rand() % 101 + 100 << endl;
	cout << rand() % 10000 / 100.0f << endl;

	// ��ȭ
	int iUpgrade = 0;
	cout << "Upgrade �⺻ ��ġ : ";
	cin >> iUpgrade;

	// ��ȭ Ȯ�� ���ϱ�
	float fPercent = rand() % 10000 / 100.f;

	// ��ȭ Ȯ��
	// 0 ~ 3 : 100 %, 4 ~ 6 : 40%, 7 ~ 9 : 10%, 10 ~ 13 : 1%, 14 ~ 15 : 0.01%
	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "��ȭ ����" << endl;
	else if (4 <= iUpgrade && iUpgrade <= 6)
	{
		if (fPercent < 40.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9)
	{
		if (fPercent < 10.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent < 1.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent < .01f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}

	return 0;
}