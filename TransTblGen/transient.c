// transient.c

#include "main.h"

Status printFields(void *pEntry, int nCh)
{
	TempEntry4Ch *p4Ch = NULL;
	TempEntry8Ch *p8Ch = NULL;
	int i;

	switch (nCh)
	{
	case 4:
		p4Ch = (TempEntry4Ch*)pEntry;
		printf("TST: %f\n", p4Ch->fTsT);
		for (i = 0; i < 4; i++)
			printf("PS%dCnt: %d\n", i, p4Ch->psxCnt[i]);
		printf("weighted at %d\n", p4Ch->weight);
		break;
	case 8:
		p8Ch = (TempEntry8Ch*)pEntry;
		printf("TST: %f %f\n", p8Ch->fTsT[0], p8Ch->fTsT[1]);
		for (i = 0; i < 8; i++)
			printf("PS%dCnt: %d\n", i, p8Ch->psxCnt[i]);
		printf("weighted at %d\n", p8Ch->weight);
		break;
	default:
		printf("ERROR: invalid argument: nCh=%d\n", nCh);
		return Status_InvalidArgument;
	}
	return Status_Success;
}

