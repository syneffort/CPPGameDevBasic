
#include <iostream>

// 사용자 정의 헤더일 경우 쌍따옴표 표기
#include "List.h"

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};

int OutputMenu()
{
	system("cls");
	cout << "1. 학생추가" << endl;
	cout << "2. 학생삭제" << endl;
	cout << "3. 학생탐색" << endl;
	cout << "4. 학생출력" << endl;
	cout << "5. 종료" << endl << endl;
	cout << "메뉴를 선택하세요 : ";
	int iInput = InputInt();

	if (iInput < MM_NONE || iInput > MM_EXIT)
		return MM_NONE;

	return iInput;
}

void InitList(PLIST pList)
{
	pList->iSize = 0;
	pList->pBebin = new NODE;
	pList->pEnd = new NODE;

	pList->pBebin->pNext = pList->pEnd;
	pList->pEnd->pPrev = pList->pBebin;
	pList->pBebin->pPrev = NULL;
	pList->pEnd->pNext = NULL;
}

int main()
{
	LIST tList;
	InitList(&tList);

	while (true)
	{
		int iMenu = OutputMenu();

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_INSERT:
			Insert(&tList);
			break;
		case MM_DELETE:
			Delete(&tList);
			break;
		case MM_SEARCH:
			Search(&tList);
			break;
		case MM_OUTPUT:
			Output(&tList);
			break;
		}
	}

	DestroyList(&tList);

	return 0;
}