
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

// 함수는 선언과 정의로 나눌 수 있다.
void SetNumber(int *pArray);
void Shuffle(int *pArray);
AI_MODE SelectAIMode();
void OutputNumber(int *pArray, int iBingo);
bool ChangeNumber(int *pArray, int iInput);
int SelectAINumber(int *pArray, AI_MODE eMode);
int BingoCount(int *pArray);
int BingoCountH(int *pArray);
int BingoCountV(int *pArray);
int BingoCountLT(int *pArray);
int BingoCountRT(int *pArrat);

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {};

	SetNumber(iNumber);
	SetNumber(iAINumber);

	Shuffle(iNumber);
	Shuffle(iAINumber);

	int iBingo = 0, iAIBingo = 0;

	AI_MODE eAIMode = SelectAIMode();

	while (true)
	{
		system("cls");

		cout << "===================== PLAYER =====================" << endl;
		OutputNumber(iNumber, iBingo);

		cout << "===================== AI =====================" << endl;
		switch (eAIMode)
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
		OutputNumber(iAINumber, iAIBingo);

		if (iBingo >= 5)
		{
			cout << "PLAYER 승리" << endl;
			break;
		}
		else if (iAIBingo >= 5)
		{
			cout << "AI 승리" << endl;
			break;
		}

		cout << "숫자를 입력하세요(0 : 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput > 25)
			continue;

		// 중복 bool
		bool bAcc = ChangeNumber(iNumber, iInput);

		if (bAcc)
			continue;

		ChangeNumber(iAINumber, iInput);

		iInput = SelectAINumber(iAINumber, eAIMode);

		ChangeNumber(iAINumber, iInput);
		ChangeNumber(iNumber, iInput);

		iBingo = BingoCount(iNumber);
		iAIBingo = BingoCount(iAINumber);
	}

	return 0;
}

void SetNumber(int *pArray)
{
	for (int i = 0; i < 25; i++)
	{
		pArray[i] = i + 1;
	}
}

void Shuffle(int *pArray)
{
	int iTemp, iIdx1, iIdx2;
	for (int i = 0; i < 100; i++)
	{
		iIdx1 = rand() % 25;
		iIdx2 = rand() % 25;

		iTemp = pArray[iIdx1];
		pArray[iIdx1] = pArray[iIdx2];
		pArray[iIdx2] = iTemp;
	}
}

AI_MODE SelectAIMode()
{
	int iAIMode;
	while (true)
	{
		cout << "1. EASY" << endl;
		cout << "2. HARD" << endl;
		cout << "게임 난이도 선택 : ";
		cin >> iAIMode;

		if (AM_EASY <= iAIMode && iAIMode <= AM_HARD)
			break;
	}

	return (AI_MODE)iAIMode;
}

void OutputNumber(int *pArray, int iBingo)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (pArray[i * 5 + j] == INT_MAX)
				cout << "*\t";
			else
				cout << pArray[i * 5 + j] << "\t";
		}
		cout << endl;
	}

	cout << "빙고 줄 : " << iBingo << endl << endl;
}

bool ChangeNumber(int *pArray, int iInput)
{
	for (int i = 0; i < 25; i++)
	{
		if (iInput == pArray[i])
		{
			pArray[i] = INT_MAX;

			return false;
		}
	}

	return true;
}

int SelectAINumber(int *pArray, AI_MODE eMode)
{
	// 선택되지 않은 숫자 배열
	int iNoneSelect[25] = {};
	int iNoneSelectCount = 0;

	switch (eMode)
	{
	case AM_EASY:
		iNoneSelectCount = 0;
		for (int i = 0; i < 25; i++)
		{
			if (pArray[i] != INT_MAX)
			{
				iNoneSelect[iNoneSelectCount] = pArray[i];
				iNoneSelectCount++;
			}
		}

		return iNoneSelect[rand() % iNoneSelectCount];
	case AM_HARD:
		int iLine = 0;
		int iStarCount = 0;
		int iSaveCount = 0;

		// 가로 최빈
		iStarCount = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (pArray[i * 5 + j] == INT_MAX)
					iStarCount++;
			}

			if (iStarCount < 5 && iStarCount > iSaveCount)
			{
				iLine = i; // LINE_NUMBER 열거형 값
				iSaveCount = iStarCount;
			}
		}

		//가로 초과하는 세로 최빈
		iStarCount = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (pArray[j * 5 + i] == INT_MAX)
					iStarCount++;
			}

			if (iStarCount < 5 && iStarCount > iSaveCount)
			{
				iLine = i + 5; // LINE_NUMBER 열거형 값
				iSaveCount = iStarCount;
			}
		}

		// 좌->우 대각 최빈
		iStarCount = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (pArray[i] == INT_MAX)
				iStarCount++;
		}

		if (iStarCount < 5 && iStarCount > iSaveCount)
		{
			iLine = LN_LT;
			iSaveCount = iStarCount;
		}

		// 우->좌 대각 최빈
		iStarCount = 0;
		for (int i = 4; i < 20; i += 4)
		{
			if (pArray[i] == INT_MAX)
				iStarCount++;
		}

		if (iStarCount < 5 && iStarCount > iSaveCount)
		{
			iLine = LN_RT;
			iSaveCount = iStarCount;
		}

		// 값 선택
		if (iLine <= LN_H5)
		{
			for (int i = 0; i < 5; i++)
			{
				if (pArray[iLine * 5 + i] != INT_MAX)
				{
					return pArray[iLine * 5 + i];
					break;
				}
			}
		}
		else if (iLine <= LN_V5)
		{
			for (int i = 0; i < 5; i++)
			{
				if (pArray[(iLine - 5) + i * 5] != INT_MAX)
				{
					return pArray[(iLine - 5) + i * 5];
				}
			}
		}
		else if (iLine == LN_LT)
		{
			for (int i = 0; i < 25; i += 6)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}
		else if (iLine == LN_RT)
		{
			for (int i = 4; i <= 20; i += 4)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}

			break;
		}

		return -1;
	}
}

int BingoCount(int *pArray)
{
	int iBingo = 0;

	iBingo += BingoCountH(pArray);
	iBingo += BingoCountV(pArray);
	iBingo += BingoCountLT(pArray);
	iBingo += BingoCountRT(pArray);

	return iBingo;
}

int BingoCountH(int *pArray)
{
	int iStar1 = 0, iBingo = 0;

	for (int i = 0; i < 5; i++)
	{
		iStar1 = 0;
		for (int j = 0; j < 5; j++)
		{
			// 가로 체크
			if (pArray[i * 5 + j] == INT_MAX)
				iStar1++;
		}

		if (iStar1 == 5)
			iBingo++;
	}

	return iBingo;
}

int BingoCountV(int *pArray)
{
	int iStar1 = 0, iBingo = 0;

	for (int i = 0; i < 5; i++)
	{
		iStar1 = 0;
		for (int j = 0; j < 5; j++)
		{
			// 세로 체크
			if (pArray[j * 5 + i] == INT_MAX)
				iStar1++;
		}

		if (iStar1 == 5)
			iBingo++;
	}

	return iBingo;
}

int BingoCountLT(int *pArray)
{
	// 좌->우 대각 체크
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 25; i += 6)
	{
		if (pArray[i] == INT_MAX)
			iStar1++;
	}

	if (iStar1 == 5)
		iBingo++;

	return iBingo;
}

int BingoCountRT(int *pArrat)
{
	// 우->좌 대각 최빈
	int iStar1 = 0, iBingo = 0;
	for (int i = 4; i < 21; i += 4)
	{
		if (pArrat[i] == INT_MAX)
			iStar1++;
	}

	if (iStar1 == 5)
		iBingo++;

	return iBingo;
}
