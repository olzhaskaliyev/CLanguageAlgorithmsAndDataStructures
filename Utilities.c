#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int i = 0;
int a = 1;
int b = 2;
int* ptr = &a;

inline long double getRandomNumber(long double rangeFrom, long double rangeTo, int decimalsCount)
{
	long double precision = pow(0.1, decimalsCount);
	return (rand() % ((int)(rangeTo / precision - rangeFrom / precision))+(rangeFrom / precision)) * precision;
}

// Inputs
long double inputNumber(char* printText)
{
	long double n;
	printf(printText);
	scanf_s("%Lf", &n);
	return n;
}

// Arrays
// Inits Arrays
inline float* initArray(int length)
{
	return calloc(length, sizeof(float));
}

float** init2DArray(int rows, int cols)
{
	float** arr = calloc(rows, sizeof(float*));
	for (int row = 0; row < rows; row++)
		arr[row] = initArray(cols);
	return arr;
}

float*** init3DArray(int pages, int rows, int cols)
{
	float*** arr = calloc(pages, sizeof(float**));
	for (int page = 0; page < pages; page++)
		arr[page] = init2DArray(rows, cols);
	return arr;
}

// Fills Arrays
void fillArrayRandomly
(
	float* arr,
	int arrLength,
	float rangeFrom,
	float rangeTo,
	int decimalsCount
)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = getRandomNumber(rangeFrom, rangeTo, decimalsCount);
}

void fill2DArrayRandomly
(
	float** arr,
	int rows,
	int cols,
	float rangeFrom,
	float rangeTo,
	int decimalsCount
)
{
	for (int row = 0; row < rows; row++)
		fillArrayRandomly(arr[row], cols, rangeFrom, rangeTo, decimalsCount);
}

void fill3DArrayRandomly
(
	float*** arr,
	int pages,
	int rows,
	int cols,
	float rangeFrom,
	float rangeTo,
	int decimalsCount
)
{
	for (int page = 0; page < pages; page++)
		fill2DArrayRandomly(arr[page], rows, cols, rangeFrom, rangeTo, decimalsCount);
}

// Prints Arrays
void printArray(float* arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
		printf("%.0f\t", arr[i]);
	printf("\n");
}

void print2DArray(float** arr, int rows, int cols)
{
	for (int row = 0; row < rows; row++)
		printArray(arr[row], cols);
}

void print3DArray(float*** arr, int pages, int rows, int cols)
{
	for (int page = 0; page < pages; page++)
	{
		print2DArray(arr[page], rows, cols);
		if (page != pages - 1)
			printf("\n");
	}
}

// Delete arrays
void free2DArray(float** arr, int rows)
{
	for (int row = 0; row < rows; row++)
		free(arr[row]);
	free(arr);
}

void free3DArray(float*** arr, int pages, int rows)
{
	for (int page = 0; page < pages; page++)
		free2DArray(arr[page], rows);
	free(arr);
}
