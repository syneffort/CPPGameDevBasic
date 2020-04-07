// ��� ������ �ѹ��� ���Խ�Ŵ
#pragma once

#include <iostream>

using namespace std;

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

typedef struct _tagNode
{
	STUDENT tStudent;
	_tagNode* pNext;
	_tagNode* pPrev;
}NODE, *PNODE;

typedef struct _tagList
{
	// pBegin�� pEnd�� ��������� ó���� ���� �ǹ��ϵ��� ��
	// ���� �����͸� �����ϴ� ���� �� ��� ���̿� ������
	PNODE pBebin;
	PNODE pEnd;
	int iSize;
}LIST, *PLIST;

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

void InitList(PLIST pList);
//void ClearList(PLIST pList);
void DestroyList(PLIST pList);

void Push_Back();
void Push_Front();