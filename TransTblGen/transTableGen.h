// transTableGen.h

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "ssTable.h"

#define NUM_CHANNELS 64
#define SS_DATA_FILENAME "Steady State Temperature Table From Cal 12-10-18.csv"
#define TRANS_DATA_FILENAME "Transient Data Abbreviated 10 to 45 Degree.csv"

// status code enumerations
typedef enum Status
{
	Status_GenericError = -1,
	Status_Success,
	Status_UnsupportedOption,
	Status_InvalidArgument,
} Status;

// structure definitions
typedef struct TempEntry4Ch
{
	float	fTsT;
	float	fPsxT[4];
	int		weight;
} TempEntry4Ch;

typedef struct TempEntry8Ch
{
	float	fTsT[2];
	float	fPsxT[8];
	int		weight;
} TempEntry8Ch;

