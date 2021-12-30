#include <stdlib.h>
#include <stdio.h>

void fillArray(float* arr, int arrSize)
{
	int n = 1;
	for (int i = 0; i < arrSize; i++, n++)
		arr[i] = n;
}

void fill2DArray(float **arr, int rows, int cols)
{
	int n = 1;
	for (int row = 0; row < rows; row++)
		for (int col = 0; col < cols; col++, n++)
			*(*(arr + row) + col) = n;
}

void fill3DArray(float*** arr, int pages, int rows, int cols)
{
	int n = 1;
	for (int page = 0; page < pages; page++)
		for (int row = 0; row < rows; row++)
			for (int col = 0; col < cols; col++)
				arr[page][row][col] = n; n++;
}

void printArray(float* arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
		printf("%.2f\t", arr[i]);
}

void print2DArray(float **arr, int rows, int cols)
{
	for (int row = 0; row < rows; row++)
		for (int col = 0; col < cols; col++)
			printf("%.2f\t", *(*(arr + row) + col));
		printf("\n");
}

void print3DArray(float*** arr, int pages, int rows, int cols)
{
	for (int page = 0; page < pages; page++)
		for (int row = 0; row < rows; row++)
			for (int col = 0; col < cols; col++)
				printf("%.2f\t", arr[page][row][col]);
}

float getRandomNumber(float rangeFrom, float rangeTo, int decimalsCount)
{
	float precision = 1;
	for (int i = 0; i < decimalsCount; i++)
		precision /= 10;
	int range = (int)(rangeTo / precision - rangeFrom / precision);
	int rangeOffset = rangeFrom / precision;
	int random = rand() % range + rangeOffset;
	return random * precision;
}

void fillArrayRandom
(
	float* arr,
	int arrSize,
	float rangeFrom,
	float rangeTo,
	int decimalsCount
)
{
	for (int i = 0; i < arrSize; i++)
		arr[i] = getRandomNumber(rangeFrom, rangeTo, decimalsCount);
}
