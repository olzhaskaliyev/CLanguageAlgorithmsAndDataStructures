/*****************************************/
/* Header section - includes and defines */
/*****************************************/

// Includes
#include <limits.h> // libraries includes with <>
#include "CLangUtils.h" // user files includes with ""

// Standard Libraries
#include <stdio.h> // core input and output functions
#include <stdlib.h> // numeric conversion functions, pseudo-random network generator, memory allocation
#include <stdint.h> // exact width integer types
#include <string.h> // string handling functions
#include <math.h> // common mathematical functions

// Defines - on compiling, preprocessor will replace keywords with expressions in code below
#define BOOL char
#define TRUE 1
#define FALSE 0

void VariablesAndConstants()
{
	// Variables
	int myVariable; // var declaration - type name
	int myVarWithInitializing = 1;

	// Constants
	const int MY_CONSTANT = 1; // const type NAME = value (init is required)
	#define MY_DEFINED_CONST 1 // define const
}

void DataTypes()
{
	// Char - 1 byte
	char myChar = -128; // -128 - 127 / %c (% - format spec)
	unsigned char myUnsignedChar = 255; // 0 - 255 / %c (unsigned - same size and range, but offset from 0)

	// Short - 2 byte
	short myShortInt = -32768; // 2 byte / -32,768 - 32,767 / %hd
	unsigned short myUnsignedShortInt = 65535; // 0 - 65,535 / %hu

	// Integer - 2 or 4 byte (size related to system)
	int myInteger = INT_MIN; // -32,768 - 32,767 or -2,147,483,648 - 2,147,483,647 / %d (size and range rel to system)
	unsigned int myUnsignedInt = 4294967295; // 0 - 32,767 or 4,294,967,295 / %u

	// Long - 4 bytes
	long myLongInt = LONG_MIN; // -2,147,483,648 - 2,147,483,647 / %ld
	unsigned long myUnsignedLongInt = 4294967295; // 4 bytes / 0 - 4,294,967,295 / %lu

	// Long Long - 8 bytes
	long long myLongLongInt = LLONG_MIN; // -9,223,372,036,854,775,808 - 9,223,372,036,854,775,807 / %lld
	unsigned long long myUnsignedLongLongInt = 18446744073709551615; // 0 - 18,446,744,073,709,551,615 / %llu

	// Float and Double
	float myFloat = 1.1; // 4 bytes / %f
	double myDoubleFloat = 1.1; // 8 bytes / %lf
	long double myLongDoubleFloat = 1.1; // 16 bytes / %Lf
}

void Operators()
{
	// Unary
	a++; a--; // (a), a = a + 1
	++a; --a; // (a + 1), a = a + 1
	!a; // a = a ? false : true
	&a; // get address of var
	*ptr; // get var from pointer address

	// Binary
	a + b; a - b; a* b; a / b; a% b; // arithmetic
	a = b; a += b; a -= b; a *= b; a /= b; a %= b; // assignment
	a < b; a > b; a <= b; a >= b; a == b; a != b; // comparative
	a&& b; a || b; // logical

	// Ternary
	a ? a : b; // if a is true, then return a, otherwise return b

	// Special
	sizeof(int); // return size in bytes

	// Operators grouping
	a = (a + b) * (a - b);
}

void ConditionalsAndLoops()
{
	// Conditionals
	{
		// If else
		if (condition)
		{
			statementA;
		}
		else
		{
			statementB;
		}

		// Switch
		switch (expression)
		{
		case expressionResA:
			statementA;
			break;
		case expressionResB:
			statementB;
			break;
		default:
			statement;
			break;
		}
	}

	// Loops
	{
		// While
		while (condition)
		{
			statement;
		}

		// Do while
		do
		{
			statement;
		} while (condition);

		// For
		for (int i = 0; i < 10; i++)
		{
			statement;
			// printf("%d\n", i);
		}
	}
}

void StaticArrays()
{
	// Static Arrays - unmutable size
	int myArrWithInit[4] = { 1, 2, 3, 4 }; // arr declaration - type name[const size] = {values}

	int myStaticArray[ARR_COLS];

	for (int i = 0; i < ARR_COLS; i++)
		myStaticArray[i] = i + 1;

	printf("My Static Array:\n");
	for (int i = 0; i < ARR_COLS; i++)
	{
		printf("%d\t", myStaticArray[i]);
	}
	printf("\n\n");

	// Multidimentional arrays
	int my2DArrWithInit[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };

	int my2DArr[ARR_ROWS][ARR_COLS];

	for (int row = 0; row < ARR_ROWS; row++)
		for (int col = 0; col < ARR_COLS; col++)
			my2DArr[row][col] = row * ARR_COLS + col + 1;

	printf("My 2D Static Array:\n");
	for (int row = 0; row < ARR_ROWS; row++)
	{
		for (int col = 0; col < ARR_COLS; col++)
		{
			printf("%d\t", my2DArr[row][col]);
		}
		printf("\n");
	}
	printf("\n");

	int my3DArrWithInit[2][3][4] =
	{
		{
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12}
		},
		{
			{13, 14, 15, 16},
			{17, 18, 19, 20},
			{21, 22, 23, 24}
		}
	};

	int my3DArr[ARR_PAGES][ARR_ROWS][ARR_COLS];

	int n = 1;
	for (int page = 0; page < ARR_PAGES; page++)
		for (int row = 0; row < ARR_ROWS; row++)
			for (int col = 0; col < ARR_COLS; col++, n++)
				my3DArr[page][row][col] = n;

	printf("My 3D Static Array:\n");
	for (int page = 0; page < ARR_PAGES; page++)
	{
		for (int row = 0; row < ARR_ROWS; row++)
		{
			for (int col = 0; col < ARR_COLS; col++)
			{
				printf("%d\t", my3DArr[page][row][col]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void PointersAndMemoryAllocation()
{
	// Pointers
	{
		int* myPointer; // store address
		int* myPtrWithInit = &a; // init accept only addresses
		int* myPtrWithInitNull = NULL;

		myPointer = &a; // set address of var
		(myPointer); // get address of pointer

		*myPointer = 3; // set value to var from pointer address
		(*myPointer); // get var from pointer address
	}

	// MemoryAllocation
	{
		// Malloc - allocate memory
		int* myPointer = malloc(sizeof(int)); // malloc(size in bytes) // returns address of allocated memory 

		// Calloc - allocate memory N times
		int* myDynamicArr = calloc(ARR_COLS, sizeof(int));

		// Realloc - re-allocate memory
		myDynamicArr = realloc(myDynamicArr, sizeof(int) * 3);

		// Free - free memory to prevent memory leak
		free(myPointer);
		free(myDynamicArr);
	}

	// PointersArithmetic
	{
		int* myDynamicArr = calloc(ARR_COLS, sizeof(int)); // int myArr[ARR_COLS];

		for (int i = 0, n = 1; i < ARR_COLS; i++, n++)
			*(myDynamicArr + i) = n; // myArr[i] = n;

		printf("My Dynamic Arr\n");
		for (int i = 0; i < ARR_COLS; i++)
			printf("%d\t", *(myDynamicArr + i)); // printf("%d\t", myArr[i]);
		printf("\n\n");

		free(myDynamicArr);
	}
}

void DynamicArrays()
{
	int userArrPages, userArrRows, userArrCols;

	printf("Enter arr pages: ");
	scanf_s("%d", &userArrPages);
	printf("Enter arr rows: ");
	scanf_s("%d", &userArrRows);
	printf("Enter arr cols: ");
	scanf_s("%d", &userArrCols);

	// In dynamic array, you need first allocate memory for each nested arr
	int*** my3DDynamicArr = calloc(userArrPages, sizeof(int**));

	for (int page = 0; page < userArrPages; page++)
		my3DDynamicArr[page] = calloc(userArrRows, sizeof(int*));

	for (int page = 0; page < userArrPages; page++)
		for (int row = 0; row < userArrRows; row++)
			my3DDynamicArr[page][row] = calloc(userArrCols, sizeof(int));

	// Fill array
	int n = 1;
	for (int page = 0; page < userArrPages; page++)
		for (int row = 0; row < userArrRows; row++)
			for (int col = 0; col < userArrCols; col++, n++)
				my3DDynamicArr[page][row][col] = n;

	// Print array
	for (int page = 0; page < userArrPages; page++)
	{
		for (int row = 0; row < userArrRows; row++)
		{
			for (int col = 0; col < userArrCols; col++, n++)
			{
				printf("%d\t", my3DDynamicArr[page][row][col]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");

	// In dynamic array, you need free each nested arr
	for (int page = 0; page < userArrPages; page++)
		for (int row = 0; row < userArrRows; row++)
			free(my3DDynamicArr[page][row]);

	for (int page = 0; page < userArrPages; page++)
		free(my3DDynamicArr[page]);

	free(my3DDynamicArr);
}

void Strings()
{

}

void Enums()
{

}

void Structs()
{

}

void Functions() {}

int myFunction(int, int); // function prototype - type name(args)

int myFunction(int arg1, int arg2) // function implementation - type name(args) {return type}
{
	int myFuncVar = arg1 + arg2;
	return myFuncVar;
}

void Scope() {}

// Global scope - var available everywhere
int myGlobalVar;

void myFuncLocalScope()
{
	// Local scope - var available only between brackets
	int myFuncLocalVar;
	{
		int mylocalVar;
	}
}
