// main.h

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "ssTable.h"
#include "transient.h"

#define NUM_CHANNELS 64
#define SS_DATA_FILENAME "Steady State Temperature Table From Cal 12-10-18.csv"
#define TRANS_DATA_FILENAME "Transient Data Abbreviated 10 to 45 Degree.csv"

typedef enum Status
{
	Status_GenericError = -1,
	Status_Success,
	Status_UnsupportedOption,
	Status_InvalidArgument,
} Status;

