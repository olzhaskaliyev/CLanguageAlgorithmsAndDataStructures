#include <stdlib.h>
#include <stdio.h>
#include "Utilities.h"
#include "Programs.h"

void randomArray()
{
	int userArrDimentions = 1, userArrSize = 0, userDecimalsCount = 0;
	float userRandomRangeFrom, userRandomRangeTo;

	do {
		printf("Enter your array dimentions count: ");
		scanf_s("%i", &userArrDimentions);
	} while (userArrDimentions < 1 || userArrDimentions > 3);

	do {
		printf("Enter your length for array: ");
		scanf_s("%i", &userArrSize);
	} while (userArrSize < 1);

	printf("Enter your random range from: ");
	scanf_s("%f", &userRandomRangeFrom);

	printf("Enter your random range to: ");
	scanf_s("%f", &userRandomRangeTo);

	printf("Enter your decimals count: ");
	scanf_s("%i", &userDecimalsCount);

	if (userArrDimentions == 1)
	{
		float* myDynamicArr = malloc(sizeof(float) * userArrSize);
	}

	if (userArrDimentions == 2)
	{
		float** myDynamicArr = malloc(sizeof(float) * userArrSize);
	}

	if (userArrDimentions == 3)
	{
		float*** myDynamicArr = malloc(sizeof(float) * userArrSize);
	}

	float *myDynamicArr = malloc(sizeof(float) * userArrSize);
	fillArrayRandom(myDynamicArr, userArrSize, userRandomRangeFrom, userRandomRangeTo, userDecimalsCount);

	printf("Your array:\n");
	printArray(myDynamicArr, userArrSize);

	free(myDynamicArr);
}
