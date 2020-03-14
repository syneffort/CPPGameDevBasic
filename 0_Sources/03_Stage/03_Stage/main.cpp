
#include <iostream>
#include <time.h>

using namespace std;

enum NUM
{
	NUM_0,
	NUM_1,
	NUM_2,
	NUM_3,
};

#define NUM_4  4

enum SRP
{
	SRP_S = 1,
	SRP_R,
	SRP_P,
	SRP_END
};

int main()
{
	// switch 문
	int iNumber = 0;
	cout << "숫자를 입력하세요 : ";
	//cin >> iNumber;

	switch (iNumber)
	{
	case NUM_1:
		cout << "1 입니다" << endl;
		break;
	case NUM_2:
		cout << "2 입니다" << endl;
		break;
	case NUM_3:
		cout << "3 입니다" << endl;
		break;
	case NUM_4:
		cout << "4 입니다" << endl;
		break;
	default:
		cout << "그 외 값 입니다." << endl;
		break;
	}

	// 열거체 타입의 변수는 4byte 소요
	//
	NUM eNum = (NUM)10;


	cout << sizeof(NUM) << endl;
	cout << typeid(NUM).name() << endl;
	cout << eNum << endl;
	{

	};

	// 반복문 : for, while, do while
	iNumber = 0;
	while (iNumber < 10)
	{
		cout << iNumber << endl;
		++iNumber;

		if (iNumber == 4)
			break;
	}

	// 화면을 지움
	system("cls");

	srand((unsigned int)time(0));

	int iPlayer;
	int iAI;

	while (false)
	{
		cout << "1. 가위" << endl;
		cout << "2. 바위" << endl;
		cout << "3. 보" << endl;
		cout << "4.종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		cin >> iPlayer;

		if (iPlayer < SRP_S || iPlayer > SRP_END)
		{
			cout << "잘못된 값을 입력하였습니다." << endl;
			// 일시정지
			system("pause");
			continue;
		}
		else if (iPlayer == 4)
			break;

		// 봇이 선택
		iAI = rand() % 3 + SRP_S;

		switch (iAI)
		{
		case SRP_S:
			cout << "AI : 가위" << endl;
		case SRP_R:
			cout << "AI : 바위" << endl;
		case SRP_P:
			cout << "AI : 보" << endl;
		default:
			break;
		}

		int iWin = iPlayer - iAI;

		/*if (iWin == 1 || iWin == -2)
			cout << "Player 승리" << endl;
		else if (iWin == 0)
			cout << "비김" << endl;
		else
			cout << "AI 승리" << endl;*/

		switch (iWin)
		{
		case 1:
		case -2:
			cout << "플레이서 승리" << endl;
		case 0:
			cout << "비김" << endl;
		default:
			cout << "봇 승리" << endl;
		}
	}

	// 트리 만들기

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3 - i; j++)
		{
			cout << " ";
		}

		for (int j = 0; j < (2 *i) + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	// 구구단 출력

	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << "*" << j << "=" << i * j << endl;
		}
	}

	/*
	2단	3단	4단
	5단	6단	7단
	8단	9단	10단
	*/

	for (int i = 2; i < 11; i += 3)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << "*" << j << "=" << i * j << "\t";
			cout << i + 1 << "*" << j << "=" << (i + 1) * j << "\t";
			cout << i + 2 << "*" << j << "=" << (i + 2) * j << endl;
		}
		cout << endl;
	}

	/*
	   *
	  ***
	 *****
	*******
	 *****
	  ***
	   *
	
	분석
	7줄
	공백	별
	3		1
	2		3
	1		5
	0		7
	1		5
	2		3
	3		1
	*/

	int iLine = 7;
	int iCount = 0;

	for (int i = 0; i < iLine; i++)
	{
		iCount = i;
		if (i > iLine / 2)
			iCount = iLine - 1 - i;

		// 공백		: 3, 2, 1, 0, 1, 2, 3
		// 별		: 1, 3, 5, 7, 5, 3, 1
		// 카운트:	: 0, 1, 2, 3, 2, 1, 0

		for (int j = 0; j < iLine / 2 - iCount; j++)
		{
			cout << " ";
		}

		for (int j = 0; j < iCount * 2 + 1; j++)
		{
			cout << "*";
		}

		cout << endl;
	}

	/*
	do while 문
	while 대비 최초 1회 구동 후 조건 테스트 실행
	*/

	int iNumber2 = 0;

	do
	{
		cout << iNumber2 << endl;
	} while (iNumber2 > 0);

	/*
	배열
	*/

	int iArray1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int iArray2[10] = { 1, 2, 3, 4, 5 }; // 입력되지 않은 값 0
	//int iArray3[10] = {}; // 모든 값 0

	for (int i = 0; i < 10; i++)
	{
		cout << iArray1[i] << endl;
	}

	// 다차원 배열
	int iArray2[10][10] = { { 1, 2, 3, }, { 4, 5, 6 } };
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << iArray2[i][j] << "\t";
		}
		cout << endl;
	}

	system("cls");

	// Lotto Program

	srand((unsigned int)time(0));
	
	int iLotto[45] = {};
	for (int i = 0; i < 45; i++)
	{
		iLotto[i] = i + 1;
	}
	// Swap algorithm
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}

	for (int i = 0; i < 6; i++)
	{
		cout << iLotto[i] << "\t";
	}
	cout << "Bonus : " << iLotto[6] << endl;

	system("cls");

	// 야구 게임
	int iPitch[9] = {};
	for (int i = 0; i < 9; i++)
	{
		iPitch[i] = i + 1;
	}

	int iTmp, index1, index2;
	for (int i = 0; i < 50; i++)
	{
		index1 = rand() % 9;
		index2 = rand() % 9;

		iTmp = iPitch[index1];
		iPitch[index1] = iPitch[index2];
		iPitch[index2] = iTmp;
	}

	cout << iPitch[0] << "\t" << iPitch[1] << "\t" << iPitch[2] << endl;

	int iStrike = 0;
	int iBall = 0;

	int iInput[3];
	while (true)
	{
		cout << "1 ~ 9 사이 숫자 중 숫자 3개를 입력하세요. (0 입력시 종료)" << endl;
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;
		else if (iInput[0] < 0 || iInput[0] > 9
			|| iInput[1] < 0 || iInput[1] > 9
			|| iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "잘못된 숫자를 입력하였습니다." << endl;
			continue;
		}
		else if (iInput[0] == iInput[1] || iInput[0] == iInput[2] || iInput[1] == iInput[2])
		{
			cout << "중복된 숫자를 입력하였습니다." << endl;
			continue;
		}
		
		iStrike = iBall = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (iPitch[i] == iInput[j])
				{
					if (i == j)
						iStrike++;
					else
						iBall++;
				}
			}
		}

		if (iStrike == 3)
		{
			cout << "숫자를 모두 맞추었습니다." << endl;
			break;
		}
		else if (iStrike == 0 && iBall == 0)
			cout << "Out" << endl;
		else
			cout << iStrike << " Strike " << iBall << " Ball" << endl;  


	}



	return 0;
}