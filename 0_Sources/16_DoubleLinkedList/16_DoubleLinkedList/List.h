// 헤더 파일을 한번만 포함시킴
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
	// pBegin과 pEnd는 명시적으로 처음과 끝을 의미하도록 함
	// 실제 데이터를 저장하는 노드는 두 노드 사이에 존재함
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