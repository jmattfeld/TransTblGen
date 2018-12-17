// transTableGen.c : This file contains the 'transTableGen' function. Program execution begins and ends there.
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include "transTableGen.h"

// globals
SSTempTable ssTbl[NUM_CHANNELS];

// function definitions

int readLine(FILE *fp, char * tstr)
{
    int c;
    int i = 0;
    int bEof = 0;

	while (1)
    {
		c = fgetc(fp);
		if (c == EOF)
        {
			// End of file encountered
			tstr[i] = 0;
			bEof = 1;
			break;
		}
		else if ((c == '\r') || (c == '\n'))
        {
			// End of line
			tstr[i] = 0;
			i = 0;
			break;
		}
		else
        {
			// Build the string, dont return
			tstr[i] = (char)c;
			i++;
		}
	}
	return(bEof);
}

TempGroup * tempGroupAlloc()
{
	TempGroup *pStruct = (TempGroup *)malloc(sizeof(TempGroup));
	return pStruct;
}

Status generateTransientTable()
{
	Status status = Status_Success;
	FILE *fp;
	char tstr[4000];
	char *ptstr;
	char *data[72];
	int i;

	// declare tempGroup lists
	SList *TransTable[12];

	// open file
	fp = fopen(TRANS_DATA_FILENAME, "r");

	if (!fp)
	{
		printf("ERROR opening %s\n", TRANS_DATA_FILENAME);
		return Status_GenericError;
	}
	printf("Opened file %s\n", TRANS_DATA_FILENAME);

	while (1)
	{
		if (readLine(fp, tstr))
			break;

		// tstr is pointing to one comma delimited sting of transient data
		// organize by temp chip mapping association
		// format of transient data (72 fields):
		// <TST1> .. <TST8> <PSC1> .. <PSC64>
		ptstr = strtok(tstr, ",\r\n");
		for (i = 0; NULL != ptstr; i++)
		{
			data[i] = ptstr;
			ptstr = strtok(NULL, ",\r\n");
		}

		// TST1:
		// TST2:
			// handle grp1 grp12 grp2
		// TST3:
		// TST4:
			// handle grp3 grp34 grp4
		// TST5:
		// TST6:
			// handle grp5 grp56 grp6
		// TST7:
		// TST8:
			// handle grp7 grp78 grp8
	}
	fclose(fp);
	printf("Closed file %s\n", TRANS_DATA_FILENAME);

	return status;
}

Status readSteadyStateTable()
{
	Status status = Status_Success;
	FILE *fp;
	char tstr[1000];
	char *ptstr;
	int ret, px, s;

	// open file
	fp = fopen(SS_DATA_FILENAME, "r");

	if (!fp)
	{
		printf("ERROR opening %s\n", SS_DATA_FILENAME);
		return Status_GenericError;
	}
	printf("Opened file %s\n", SS_DATA_FILENAME);

	// read the steady state data into a structure
	// format: <psIdx> <stepIdx> <tsTemp> <psCnt>
	//while (1)
	for (px = 1; px < 65; px++)
	{
		for (s = 0; s < 15; s++)
		{
			ret = readLine(fp, tstr);

#ifdef DEBUG
			printf("readLine returned: %d\n", ret);
			printf("Line: %s\n", tstr);
#endif
			// Have one line, load SSTempTable struct
			// discard the first two tokens
			strtok(tstr, ",\r\n");	// px idx
			strtok(NULL, ",\r\n");	// step idx
			ptstr = strtok(NULL, ",\r\n");	// tsTemp
			sscanf(ptstr, "%f", &ssTbl[px].tsTemp[s]);
			ptstr = strtok(NULL, ",\r\n");	// psCnt
			sscanf(ptstr, "%d", &ssTbl[px].psCnt[s]);
		}
	}
	fclose(fp);
	printf("Closed file %s\n", SS_DATA_FILENAME);
	return Status_Success;
}

int main()
{
	Status status = Status_Success;
	int i;

	// read steady state data into structure
	if (Status_Success != (status = readSteadyStateTable()))
	{
		printf("ERROR parsing steady state table\n");
		return Status_GenericError;
	}
	printf("Finished parsing %s\n", SS_DATA_FILENAME);

	// calculate slope/intercept values from steady state data
	for (i = 0; i < 64; i++)
	{
		if (Status_Success != (status = calculateLineEqs(&ssTbl[i])))
		{
			printf("ERROR calculating line equations for ssTbl[%d]\n", i);
			return Status_GenericError;
		}

	}
	printf("Finished calculating line equations\n");

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

