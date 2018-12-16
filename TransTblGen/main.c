// TransTblGen.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "main.h"

// globals
SSTempTable ssTbl[NUM_CHANNELS];

int main()
{
	Status status = Status_Success;

#pragma region List Tests
	//SList *head = NULL;
	//SList *current = NULL;

	//TempEntry4Ch grp1;
	//grp1.fTsT = 15.05;
	//grp1.psxCnt[0] = 25000;
	//grp1.weight = 1;
	//head = prepend(head, &grp1);

	//TempEntry4Ch grp2;
	//grp2.fTsT = 16.05;
	//grp2.psxCnt[0] = 35000;
	//grp2.weight = 2;
	//head = prepend(head, &grp2);

	//TempEntry4Ch grp3;
	//grp3.fTsT = 17.05;
	//grp3.psxCnt[0] = 45000;
	//grp3.weight = 3;
	//head = prepend(head, &grp3);

	//TempEntry4Ch grp4;
	//grp4.fTsT = 18.05;
	//grp4.psxCnt[0] = 55000;
	//grp4.weight = 4;
	//head = prepend(head, &grp4);

	//current = head;
	//do
	//{
	//	printFields(current->data, 4);
	//	printf("current->next: %p\n", current->next);
	//	current = current->next;
	//} while (NULL != current);

	//reverse(&head);

	//current = head;
	//do
	//{
	//	printFields(current->data, 4);
	//	printf("current->next: %p\n", current->next);
	//	current = current->next;
	//} while (NULL != current);
#pragma endregion

#pragma region Solid State Table TestCode
	//int i;
	//float fInc = 0.0625;
	//int iInc[] = { 1, 10, 100, 1000, 10000,
	//			  100000, 10000, 1000, 100, 10,
	//			  1, 10, 100, 1000, 10000 };

	//for (i = 0; i < 15; i++)
	//{
	//	ssTbl[0].tsTemp[i] = 15.000 + i*fInc;
	//	ssTbl[0].psCnt[i] =  iInc[i]*2;
	//}
	//// read the steady state data into a structure
	//for (i = 0; i < 15; i++)
	//{
	//	printf("TST[%d]: %f\tPSC[%d]: %d\n", i, ssTbl[0].tsTemp[i], i, ssTbl[0].psCnt[i]);
	//}

	//if (Status_Success == calculateLineEqs(&ssTbl[0]))
	//{
	//	// print result
	//	for (i = 0; i < 15; i++)
	//	{
	//		printf("slope[%d]: %f\tintercept[%d]: %f\n", i, ssTbl[0].m[i], i, ssTbl[0].b[i]);
	//	}
	//}

	//float ret;
	//if (Status_Success == calculatePxTemp(&ssTbl[0], 555, &ret))
	//	printf("returned temp: %f\n", ret);
	//else
	//	printf("calculatePxTemp returned error\n");
#pragma endregion

	return status;
}

