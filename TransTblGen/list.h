// list.h

#ifndef LIST_H
#define LIST_H

typedef struct SList
{
	void			*data;
	struct SList	*next;
} SList;

SList * prepend(SList * pList, void * pData);
void reverse(SList ** pList);

#endif //LIST_H
