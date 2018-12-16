// main.h

#include <stdio.h>
#include "list.h"
#include "ssTable.h"
#include "transient.h"

#define NUM_CHANNELS 64

typedef enum Status
{
	Status_Error = -1,
	Status_Success,
} Status;

