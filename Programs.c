#include <stdio.h>
#include <stdlib.h>
#include "Utilities.h"

void userArray()
{
	float*** userArray;
	unsigned char userArrayPages = inputNumber("Enter array pages: ");
	unsigned char userArrayRows = inputNumber("Enter array rows: ");
	unsigned char userArrayCols = inputNumber("Enter array cols: ");
	float userRandomRangeFrom = inputNumber("Enter random range from: ");
	float userRandomRangeTo = inputNumber("Enter random range to: ");
	unsigned char userRandomDecimalsCount = inputNumber("Enter random decimals count: ");
	printf("\n");

	userArray = init3DArray(userArrayPages, userArrayRows, userArrayCols);
	fill3DArrayRandomly
	(
		userArray,
		userArrayPages,
		userArrayRows,
		userArrayCols,
		userRandomRangeFrom,
		userRandomRangeTo,
		userRandomDecimalsCount
	);
	print3DArray(userArray, userArrayPages, userArrayRows, userArrayCols);
	free3DArray(userArray, userArrayPages, userArrayRows);
}
