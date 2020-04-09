 
#include "List.h"

void OutputStudent(const PSTUDENT pStudent)
{
	cout << "이름 : " << pStudent->strName << "\t학번 : " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << "\t영어 : " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << endl;
	cout << "총점 : " << pStudent->iTotal << "\t평균 : " << pStudent->fAvg << endl << endl;
}

void InitList(PLIST pList)
{
	pList->iSize = 0;
	pList->pBegin = new NODE;
	pList->pEnd = new NODE;

	pList->pBegin->pNext = pList->pEnd;
	pList->pEnd->pPrev = pList->pBegin;
	pList->pBegin->pPrev = NULL;
	pList->pEnd->pNext = NULL;
}

void DestroyList(PLIST pList)
{
	PNODE pNode = pList->pBegin;
	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}

	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;
}

void Push_Back(PLIST pList)
{
	system("cls");
	cout << "==================== 학생추가 ====================" << endl;

	STUDENT tStudent = {};

	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);
	cout << "학번 : ";
	tStudent.iNumber = InputInt();
	cout << "국어 : ";
	tStudent.iKor = InputInt();
	cout << "영어 : ";
	tStudent.iEng = InputInt();
	cout << "수학 : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	PNODE pNode = new NODE;
	pNode->tStudent = tStudent;

	PNODE pPrev = pList->pEnd->pPrev;
	pPrev->pNext = pNode;
	pNode->pPrev = pPrev;
	pNode->pNext = pList->pEnd;
	pList->pEnd->pPrev = pNode;
	pList->iSize++;
}

void Push_Front()
{

}

void Output(PLIST pList)
{
	int iMenu;
	while (true)
	{
		system("cls");
		cout << "==================== 학생출력 ====================" << endl;
		cout << "1. 정방향 출력" << endl;
		cout << "2. 역방향 출력" << endl;
		cout << "메뉴를 선택하세요 : ";
		iMenu = InputInt();
		
		if (iMenu > OT_NONE && iMenu <= OT_REVERSE)
			break;
	}
	
	PNODE pNode = NULL;
	switch (iMenu)
	{
	case OT_OUTPUT:
		pNode = pList->pBegin->pNext;
		while (pNode != pList->pEnd)
		{
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pNext;
		}
		break;
	case OT_REVERSE:
		pNode = pList->pEnd->pPrev;
		while (pNode != pList->pBegin)
		{
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pPrev;
		}
		break;
	}

	cout << "학생수 : " << pList->iSize << endl;
	system("pause");
}

void Search(PLIST pList)
{
	system("cls");
	cout << "==================== 학생탐색 ====================" << endl;

	cout << "탐색할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;
	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}

		pNode = pNode->pNext;
	}

	cout << "찾는 학생이 없습니다." << endl;
	system("pause");
}

void Delete(PLIST pList)
{
	system("cls");
	cout << "==================== 학생삭제 ====================" << endl;

	cout << "삭제할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;
	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			pList->iSize--;
			
			cout << strName << " 학생을 삭제했습니다." << endl;
			system("pause");
			return;
		}

		pNode = pNode->pNext;
	}

	cout << "삭제할 대상을 찾을 수 없습니다." << endl;
	system("pause");
}

void Sort(PLIST pList)
{
	system("cls");
	cout << "==================== 학생정렬 ====================" << endl;
	cout << "1. 학번" << endl;
	cout << "2. 평균" << endl;
	cout << "메뉴를 선택하세요 : ";
	int iInput = InputInt();

	if (iInput <= ST_NONE && iInput > ST_AVG)
	{
		cout << "선택값이 올바르지 않습니다." << endl;
		system("pause");
		return;
	}

	PNODE pFirst = pList->pBegin->pNext;
	PNODE pSecond = pFirst->pNext;

	while (pFirst != pList->pEnd->pPrev)
	{
		pSecond = pFirst->pNext;
		while (pSecond != pList->pEnd)
		{
			bool bSwap = false;

			switch (iInput)
			{
			case ST_NUMBER:
				if (pFirst->tStudent.iNumber > pSecond->tStudent.iNumber)
					bSwap = true;
				break;
			case ST_AVG:
				if (pFirst->tStudent.fAvg > pSecond->tStudent.fAvg)
					bSwap = true;
				break;
			}

			if (bSwap)
			{
				PNODE pFirstPrev = pFirst->pPrev;
				PNODE pFirstNext = pFirst->pNext;

				PNODE pSecondPrev = pSecond->pPrev;
				PNODE pSecondNext = pSecond->pNext;

				pFirstPrev->pNext = pSecond;
				pSecond->pPrev = pFirstPrev;

				pSecondNext->pPrev = pFirst;
				pFirst->pNext = pSecondNext;

				PNODE pTemp = pFirst;
				pFirst = pSecond;
				pSecond = pTemp;

				pFirst->pNext = pSecond;
				pSecond->pPrev = pFirst;

				/*pFirstNext->pPrev = pFirst;
				pFirst->pNext = pFirstNext;*/

				/*pSecondPrev->pNext = pSecond;
				pSecond->pPrev = pSecondPrev;*/
			}
			pSecond = pSecond->pNext;
		}
		pFirst = pFirst->pNext;
	}

	cout << "정렬이 완료되었습니다." << endl;
	system("pause");
}