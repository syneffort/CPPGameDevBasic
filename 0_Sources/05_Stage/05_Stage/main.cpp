
#include <iostream>
#include <time.h>

using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {};

	for (int i = 0; i < 25; i++)
	{
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}

	int iTemp, iIdx1, iIdx2;
	for (int i = 0; i < 100; i++)
	{
		iIdx1 = rand() % 25;
		iIdx2 = rand() % 25;

		iTemp = iNumber[iIdx1];
		iNumber[iIdx1] = iNumber[iIdx2];
		iNumber[iIdx2] = iTemp;

		iIdx1 = rand() % 25;
		iIdx2 = rand() % 25;

		iTemp = iAINumber[iIdx1];
		iAINumber[iIdx1] = iAINumber[iIdx2];
		iAINumber[iIdx2] = iTemp;
	}

	int iBingo = 0, iAIBingo = 0;

	int iAIMode;
	while (true)
	{
		cout << "1. EASY" << endl;
		cout << "2. HARD" << endl;
		cout << "���� ���̵� ���� : ";
		cin >> iAIMode;

		if (AM_EASY <= iAIMode && iAIMode <= AM_HARD)
			break;
	}

	// ���õ��� ���� ���� �迪
	int iNoneSelect[25] = {};
	int iNoneSelectCount = 0;

	while (true)
	{
		system("cls");

		cout << "===================== PLAYER =====================" << endl;
		//���� ���
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

		cout << "���� �� : " << iBingo << endl << endl;

		cout << "===================== AI =====================" << endl;
		switch (iAIMode)
		{
		case AM_EASY:
			cout << "AI mode : EASY" << endl;
			break;
		case AM_HARD:
			cout << "AI mode : HARD" << endl;
			break;
		default:
			break;
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iAINumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iAINumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << "AI ���� �� : " << iAIBingo << endl << endl;

		if (iBingo >= 5)
		{
			cout << "PLAYER �¸�" << endl;
			break;
		}
		else if (iAIBingo >= 5)
		{
			cout << "AI �¸�" << endl;
			break; 
		}

		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput > 25)
			continue;

		// �ߺ� bool
		bool bAcc = true;

		for (int i = 0; i < 25; i++)
		{
			if (iInput == iAINumber[i])
			{
				iAINumber[i] = INT_MAX;

				iNoneSelectCount--;
				break;
			}
		}

		for (int i = 0; i < 25; i++)
		{
			if (iInput == iNumber[i])
			{
				bAcc = false;

				iNumber[i] = INT_MAX;

				break;
			}
		}

		if (bAcc)
			continue;

		switch (iAIMode)
		{
		case AM_EASY:
			iNoneSelectCount = 0;
			for (int i = 0; i < 25; i++)
			{
				if (iAINumber[i] != INT_MAX)
				{
					iNoneSelect[iNoneSelectCount] = iAINumber[i];
					iNoneSelectCount++;
				}
			}

			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;
		case AM_HARD:
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;
			
			// ���� �ֺ�
			iStarCount = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (iAINumber[i * 5 + j] == INT_MAX)
						iStarCount++;
				}

				if (iStarCount < 5 && iStarCount > iSaveCount)
				{
					iLine = i; // LINE_NUMBER ������ ��
					iSaveCount = iStarCount;
				}
			}

			//���� �ʰ��ϴ� ���� �ֺ�
			iStarCount = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (iAINumber[j * 5 + i] == INT_MAX)
						iStarCount++;
				}

				if (iStarCount < 5 && iStarCount > iSaveCount)
				{
					iLine = i + 5; // LINE_NUMBER ������ ��
					iSaveCount = iStarCount;
				}
			}

			// ��->�� �밢 �ֺ�
			iStarCount = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (iAINumber[i] == INT_MAX)
					iStarCount++;
			}

			if (iStarCount < 5 && iStarCount > iSaveCount)
			{
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}

			// ��->�� �밢 �ֺ�
			iStarCount = 0;
			for (int i = 4; i < 20; i += 4)
			{
				if (iAINumber[i] == INT_MAX)
					iStarCount++;
			}

			if (iStarCount < 5 && iStarCount > iSaveCount)
			{
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}

			// �� ����
			if (iLine <= LN_H5)
			{
				for (int i = 0; i < 5; i++)
				{
					if (iAINumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}
			else if (iLine <= LN_V5)
			{
				for (int i = 0; i < 5; i++)
				{
					if (iAINumber[(iLine - 5) + i * 5] != INT_MAX)
					{
						iInput = iAINumber[(iLine - 5) + i * 5];
						break;
					}
				}
			}
			else if (iLine == LN_LT)
			{
				for (int i = 0; i < 25; i += 6)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}
			else if (iLine == LN_RT)
			{
				for (int i = 4; i <= 20; i += 4)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}
			break;
		}

		for (int i = 0; i < 25; i++)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		for (int i = 0; i < 25; i++)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}

		iBingo = 0;
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;
		for (int i = 0; i < 5; i++)
		{
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; j++)
			{
				// ���� üũ
				if (iNumber[i * 5 + j] == INT_MAX)
					iStar1++;
				
				if (iAINumber[i * 5 + j] == INT_MAX)
					iAIStar1++;

				// ���� üũ
				if (iNumber[j * 5 + i] == INT_MAX)
					iStar2++;

				if (iAINumber[j * 5 + i] == INT_MAX)
					iAIStar2++;
			}

			if (iStar1 == 5)
				iBingo++;

			if (iAIStar1 == 5)
				iAIBingo++;

			if (iStar2 == 5)
				iBingo++;

			if (iAIStar2 == 5)
				iAIBingo++;
		}

		// ��->�� �밢 üũ
		iStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				iStar1++;

			if (iAINumber[i] == INT_MAX)
				iAIStar1++;
		}

		// ��->�� �밢 üũ
		iStar2 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				iStar2++;

			if (iAINumber[i] == INT_MAX)
				iStar2++;
		}

		if (iStar1 == 5)
			iBingo++;

		if (iAIStar1 == 5)
			iAIBingo++;

		if (iStar2 == 5)
			iBingo++;

		if (iAIStar2 == 5)
			iAIBingo++;
	}
	
	return 0;
}