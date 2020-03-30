
#include <iostream>

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

#define NAME_SIZE 32

typedef struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;

}STUDENT, *PSTUDENT;

/*
링크드리스트 : 자료구조의 한 종류로 데이터 목록을 연결시켜 접근할 수 있는 구조를 제공
노드 : 데이터를 저장, 다음 노드를 알고 있음 (다음 노드 메모리 주소 저장)
단, 리스트는 선형구조이기 때문에 특정 요소에 바로 접근이 불가능하며 차례대로 타고 들어가야함
*/

// 리스트 노드
typedef struct _tagNode
{
	STUDENT tStudent;
	_tagNode* pNext;
}NODE, *PNODE;

// 리스트 구조체
typedef struct _tagList
{
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, *PLIST;

void InitList(PLIST pList)
{
	// 초기화 시 NULL 명시 하는 습관!
	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
}

int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}

	return iInput;
}

void InputString(char* pString, int iSize)
{
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);

}

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

void Insert(PLIST pList)
{
	system("cls");
	cout << "==================== 학생추가 ====================" << endl;

	STUDENT tStudent = {};

	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "국어 : ";
	tStudent.iKor = InputInt();
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
			break;
		case MM_SEARCH:
			break;
		case MM_OUTPUT:
			break;
		}
	}

	return 0;
}