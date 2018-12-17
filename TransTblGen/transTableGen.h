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
	Status_MemoryError,
} Status;

typedef enum GrpType
{
	GrpType_4Ch = 4,
	GrpType_8Ch = 8,
} GrpType;

typedef enum TempGroup
{
	TempGrp_1 = 1,
	TempGrp_12,
	TempGrp_2,
	TempGrp_3,
	TempGrp_34,
	TempGrp_4,
	TempGrp_6,
	TempGrp_56,
	TempGrp_5,
	TempGrp_8,
	TempGrp_78,
	TempGrp_7,
} TempGroup;

// structure definitions
typedef struct TempEntry
{
	TempGroup	grp;
	int			weight;
	void		*data;
} TempEntry;

typedef struct TempData4Ch
{
	float	fTsT;
	float	fPsxT[4];
} TempData4Ch;

typedef struct TempData8Ch
{
	float	fTsT;
	float	fPsxT[8];
} TempData8Ch;
