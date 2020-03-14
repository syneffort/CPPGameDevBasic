
#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

int main()
{
	// ���� ����

	srand((unsigned int)time(0));

	int iNumber[25] = {};
	for (int i = 0; i < 24; i++)
	{
		iNumber[i] = i + 1;
	}

	int iStarIndex = 24;
	iNumber[24] = INT_MAX;
	
	// 1 ~ 24 �ε��� ����
	int iTemp, iIdx1, iIdx2;
	for (int i = 0; i < 100; i++)
	{
		iIdx1 = rand() % 24;
		iIdx2 = rand() % 24;

		iTemp = iNumber[iIdx1];
		iNumber[iIdx1] = iNumber[iIdx2];
		iNumber[iIdx2] = iTemp;
	}

	while (true)
	{
		system("cls");

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		
		}

		bool bWin = true;
		for (int i = 0; i < 24; i++)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}

		if (bWin == true)
		{
			cout << "���ڸ� ��� ���߾����ϴ�." << endl;
			break;
		}

		cout << "w : �� s : �Ʒ� a : ���� d : ������  q : ���� : ";
		char cInput = _getch();
		if (cInput == 'q' || cInput == 'Q')
			break;

		switch (cInput)
		{
		case 'w':
		case 'W':
			if (iStarIndex > 4)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				iNumber[iStarIndex - 5] = INT_MAX;
				iStarIndex -= 5;
			}
			break;
		case 's':
		case 'S':
			if (iStarIndex < 20)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				iNumber[iStarIndex + 5] = INT_MAX;
				iStarIndex += 5;
			}
			break;
		case 'a':
		case 'A':
			if (iStarIndex % 5 != 0)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				iNumber[iStarIndex - 1] = INT_MAX;
				iStarIndex -= 1;
			}
			break;
		case 'd':
		case 'D':
			if (iStarIndex % 5 != 4)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				iNumber[iStarIndex + 1] = INT_MAX;
				iStarIndex += 1;
			}
			break;
		}
	}

	cout << endl << "������ �����մϴ�." << endl;

	return 0;
}