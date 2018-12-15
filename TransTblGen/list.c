// list.c
// this file defines the linked list routines
#include <stdio.h>
#include "list.h"

SList * append(SList * pList, void * pData)
{
	printf("Appended to list\n");

	return pList;
}

SList * prepend(SList * pList, void * pData)
{
	printf("Prepended to list\n");

	return pList;
}
