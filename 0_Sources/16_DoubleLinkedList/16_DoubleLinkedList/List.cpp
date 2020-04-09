 
#include "List.h"

void OutputStudent(const PSTUDENT pStudent)
{
	cout << "�̸� : " << pStudent->strName << "\t�й� : " << pStudent->iNumber << endl;
	cout << "���� : " << pStudent->iKor << "\t���� : " << pStudent->iEng << endl;
	cout << "���� : " << pStudent->iMath << endl;
	cout << "���� : " << pStudent->iTotal << "\t��� : " << pStudent->fAvg << endl << endl;
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
	cout << "==================== �л��߰� ====================" << endl;

	STUDENT tStudent = {};

	cout << "�̸� : ";
	InputString(tStudent.strName, NAME_SIZE);
	cout << "�й� : ";
	tStudent.iNumber = InputInt();
	cout << "���� : ";
	tStudent.iKor = InputInt();
	cout << "���� : ";
	tStudent.iEng = InputInt();
	cout << "���� : ";
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
		cout << "==================== �л���� ====================" << endl;
		cout << "1. ������ ���" << endl;
		cout << "2. ������ ���" << endl;
		cout << "�޴��� �����ϼ��� : ";
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

	cout << "�л��� : " << pList->iSize << endl;
	system("pause");
}

void Search(PLIST pList)
{
	system("cls");
	cout << "==================== �л�Ž�� ====================" << endl;

	cout << "Ž���� �̸��� �Է��ϼ��� : ";
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

	cout << "ã�� �л��� �����ϴ�." << endl;
	system("pause");
}

void Delete(PLIST pList)
{
	system("cls");
	cout << "==================== �л����� ====================" << endl;

	cout << "������ �̸��� �Է��ϼ��� : ";
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
			
			cout << strName << " �л��� �����߽��ϴ�." << endl;
			system("pause");
			return;
		}

		pNode = pNode->pNext;
	}

	cout << "������ ����� ã�� �� �����ϴ�." << endl;
	system("pause");
}

void Sort(PLIST pList)
{
	system("cls");
	cout << "==================== �л����� ====================" << endl;
	cout << "1. �й�" << endl;
	cout << "2. ���" << endl;
	cout << "�޴��� �����ϼ��� : ";
	int iInput = InputInt();

	if (iInput <= ST_NONE && iInput > ST_AVG)
	{
		cout << "���ð��� �ùٸ��� �ʽ��ϴ�." << endl;
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

	cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	system("pause");
}