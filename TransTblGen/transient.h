// transient.h

#ifndef TRANSIENT_H
#define TRANSIENT_H

typedef struct TempEntry4Ch
{
	float	fTsT;
	float	fPsxT[4];
	int		psxCnt[4];
	int		weight;
} TempEntry4Ch;

typedef struct TempEntry8Ch
{
	float	fTsT[2];
	float	fPsxT[8];
	int		psxCnt[8];
	int		weight;
} TempEntry8Ch;

enum Status printFields(void *pEntry, int nCh);

#endif //TRANSIENT_H
