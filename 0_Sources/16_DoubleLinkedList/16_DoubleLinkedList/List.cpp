 
#include "List.h"

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

void DestroyList(PLIST pList)
{
	PNODE pNode = pList->pBebin;
	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}

	pList->iSize = 0;
	pList->pBebin = NULL;
	pList->pEnd = NULL;
}

void Push_Back()
{

}

void Push_Front()
{

}