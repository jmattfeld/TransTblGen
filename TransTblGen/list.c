// list.c
// this file defines the linked list routines

#include "transTableGen.h"

SList * prepend(SList * pList, void * pData)
{
	SList *pNode = (struct SList*)malloc(sizeof(SList));

	if (NULL != pNode)
	{
		pNode->data = pData;
		pNode->next = pList;
	}

	return pNode;
}

void reverse(SList ** pList)
{
	SList *pPrev = NULL;
	SList *pThis = *pList;
	SList *pNext = NULL;

	while (NULL != pThis)
	{
		pNext = pThis->next;
		pThis->next = pPrev;
		pPrev = pThis;
		pThis = pNext;
	}
	*pList = pPrev;
}
