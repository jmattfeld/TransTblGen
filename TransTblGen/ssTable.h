// ssTable.h

typedef struct SSTempTable
{
	float	tsTemp[15];	// temp sensor values
	int		psCnt[15];	// raw count values
	float	m[15];		// slope
	float	b[15];		// y-axis intercept
} SSTempTable;

enum Status calculateLineEqs(SSTempTable * pTable);
enum Status calculatePxTemp(SSTempTable * pTable, int count, float *temp);
