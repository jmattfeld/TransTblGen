#ifndef LIST_H
#define LIST_H

typedef struct SList
{
	void			*data;
	struct SList	*next;
} SList;

SList * append(SList * pList, void * pData);
SList * prepend(SList * pList, void * pData);
#endif //LIST_H
