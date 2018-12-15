// ssTable.c

#include <stdbool.h>
#include "ssTable.h"
#include "status.h"
#include "list.h"


Status calculateLineEqs(SSTempTable * pTable)
{
	int s;
	float diffX;
	float diffY;

	for (s = 1; s < 15; s++)
	{
		diffX = (float)pTable->psCnt[s] - (float)pTable->psCnt[s - 1];
		printf("diffX: %f\n", diffX);
		diffY = pTable->tsTemp[s] - pTable->tsTemp[s - 1];
		printf("diffY: %f\n", diffY);
		pTable->m[s] = diffY / diffX;
		printf("slope: %f\n", pTable->m[s]);
		pTable->b[s] = pTable->tsTemp[s] - pTable->m[s] * pTable->psCnt[s];
		printf("intercept: %f\n", pTable->b[s]);
	}
	return Status_Success;
}

Status calculatePxTemp(SSTempTable * pTable, int count, float *temp)
{
	int s;
	bool bHaveStep = false;

	printf("calculating temp for count: %d\n", count);

	// find the correct temperature step
	for (s=1; s<15; s++)
	{
		if ((count > pTable->psCnt[s - 1]) && (count < pTable->psCnt[s]))
		{
			// temp = m*count + b
			printf("found step between raw counts: %d and %d\n", pTable->psCnt[s - 1], pTable->psCnt[s]);
			printf("returned temp should be between %f and %f\n", pTable->tsTemp[s - 1], pTable->tsTemp[s]);
			*temp = pTable->m[s] * (float)count + pTable->b[s];
			return Status_Success;
		}
		else
			continue;
	}
	// return error if count is not in step domain
	return Status_Error;
}