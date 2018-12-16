// TransTblGen.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "main.h"

// globals
SSTempTable ssTbl[NUM_CHANNELS];

int main()
{
	Status status;

#pragma region TestCode
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

	return 0;
}

