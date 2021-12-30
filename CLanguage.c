/*****************************************/
/* Header section - includes and defines */
/*****************************************/

// Includes
#include <limits.h> // libraries includes with <>
#include "Utilities.h" // user files includes with ""

// Standard Libraries
#include <stdio.h> // core input and output functions
#include <stdlib.h> // numeric conversion functions, pseudo-random network generator, memory allocation
#include <stdint.h> // exact width integer types
#include <string.h> // string handling functions
#include <math.h> // common mathematical functions

// Defines - on compiling, preprocessor will replace keyword to code
#define BOOL char
#define TRUE 1
#define FALSE 0

void VariablesAndConstants()
{
	// Variables
	int myVariable; // var declaration - type name
	int myVarWithInitializing = 1;

	// Constants
	const int MY_CONSTANT = 1; // const declaration - const type NAME = value (init is required)
	#define MY_DEFINED_CONST 1 // const declaration with define - #define NAME value
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

	// Types cast
	int a = (float)1.2; // (type to cast)val
}

void Operators()
{
	// Unary
	a++; a--; // (a), a = a + 1 (postfix increment and decrement)
	++a; --a; // (a + 1), a = a + 1 (prefix increment and decrement)
	!a; // a = a ? false : true

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
		else if (condition) // optional
		{
			statementB;
		}
		else // optional
		{
			statement;
		}

		// Switch
		switch (expression)
		{
		case expressionResA:
			statementA;
			break; // break continiously code
		case expressionResB:
			statementB;
			// without break next case will execute
		default:
			statement;
			break;
		}
	}

	// Loops
	{
		// While
		while (condition) // while (true) - infinite loop
		{
			statement;
			if (condition) {
				break; // break loop
			}
			if (condition)
			{
				continue; // skip current iteration
			}
		}

		// Do while
		do
		{
			statement; // executes once, then check condition for continiously executions
		} while (condition);

		// For
		for (int i = 0; i < 10; i++) // for (inits; conditions; iterations) // for (;;;) - infinite loop
		{
			statement; // exam - printf("%d\n", i) // var i available in body
		}
	}
}

void StaticArrays()
{
	// Static Arrays - unmutable size
	int myArrWithInit[] = { 1, 2, 3, 4 }; // arr declaration - type name[const size] = {values}

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

	for (int page = 0, n = 1; page < ARR_PAGES; page++)
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

void Pointers()
{
	// * Pointers store only addresses
	int* myPointer = NULL; // pointer declaration - type * name = address (NULL - nullptr - null address)
	printf("myPointer size = %lld bytes\n", sizeof(myPointer)); // 8 bytes

	// & Links
	printf("myPointer value (address) = %p\n", myPointer); // %p - string format
	myPointer = &a; // &a - get address of var
	printf("myPointer new value (address) = %p\n", myPointer);

	// *Dereference
	*myPointer; // *ptr - dereference - get var from pointer address
	printf("value of var from myPointer = %d\n", *myPointer);

	*myPointer = 3; // set val to var from pointer address
	printf("new value of var from myPointer = %d\n", *myPointer);
	printf("value of var a = %d\n", a);

	// Pointers arithmetic
	*(ptr + i); // same as ptr[i]
	printf("value of memory block next to myPointer = %d\n\n", *(ptr + i));
}

void MemoryAllocation()
{
	// Malloc - allocate memory
	int* myPtr = malloc(sizeof(int)); // malloc(size in bytes) // returns address of allocated memory or NULL

	*myPtr = 2;
	printf("myPtr value (address) = %p\n", myPtr);
	printf("value of var from myPtr = %d\n\n", *myPtr);

	// Calloc - allocate memory N times
	int* myDynamicArr = calloc(ARR_COLS, sizeof(int));

	myDynamicArr[ARR_COLS - 1] = 2;
	printf("myDynamicArr value (address) = %p\n", myDynamicArr);
	printf("value of var from myDynamicArr[ARR_COLS - 1] = %d\n\n", *(myDynamicArr + (ARR_COLS - 1)));

	// Realloc - re-allocate memory
	myDynamicArr = realloc(myDynamicArr, sizeof(int) * 3); // allocate new memory block and return address

	printf("myDynamicArr value (address) after realloc = %p\n", myDynamicArr);
	printf("value of var from myDynamicArr[ARR_COLS - 1] after realloc = %d\n\n", myDynamicArr[ARR_COLS - 1]);

	// Free - free memory to prevent memory leak
	free(myPtr);
	free(myDynamicArr);

	printf("value of var from myPtr after free = %d\n\n", *myPtr);
}

void DynamicArrays()
{
	int* myDynamicArr = calloc(ARR_COLS, sizeof(int)); // int myArr[ARR_COLS];

	for (int i = 0, n = 1; i < ARR_COLS; i++, n++)
		*(myDynamicArr + i) = n; // myArr[i] = n;

	printf("My Dynamic Arr\n");
	for (int i = 0; i < ARR_COLS; i++)
		printf("%d\t", *(myDynamicArr + i)); // printf("%d\t", myArr[i]);
	printf("\n\n");

	free(myDynamicArr);

	// Multidimentional Dynamic Arrays
	{
		// In dynamic array, you need first allocate memory for each nested arr
		int*** my3DDynamicArr = calloc(ARR_PAGES, sizeof(int**));

		for (int page = 0; page < ARR_PAGES; page++)
			*(my3DDynamicArr + page) = calloc(ARR_ROWS, sizeof(int*));

		for (int page = 0; page < ARR_PAGES; page++)
			for (int row = 0; row < ARR_ROWS; row++)
				*(*(my3DDynamicArr + page) + row) = calloc(ARR_COLS, sizeof(int));

		// Fill array
		int n = 1;
		for (int page = 0; page < ARR_PAGES; page++)
			for (int row = 0; row < ARR_ROWS; row++)
				for (int col = 0; col < ARR_COLS; col++, n++)
					*(*(*(my3DDynamicArr + page) + row) + col) = n;

		// Print array
		printf("My Dynamic 3D Arr\n");
		for (int page = 0; page < ARR_PAGES; page++)
		{
			for (int row = 0; row < ARR_ROWS; row++)
			{
				for (int col = 0; col < ARR_COLS; col++, n++)
				{
					printf("%d\t", *(*(*(my3DDynamicArr + page) + row) + col));
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");

		// In dynamic array, you need free each nested arr
		for (int page = 0; page < ARR_PAGES; page++)
			for (int row = 0; row < ARR_ROWS; row++)
				free(*(*(my3DDynamicArr + page) + row));

		for (int page = 0; page < ARR_PAGES; page++)
			free(*(my3DDynamicArr + page));

		free(my3DDynamicArr);
	}
}

void Strings()
{

}

/*************/
/* Functions */
/*************/

int myFunction(int, int); // func prototype - type name(args) // use for func available

void Functions() {
	int myFuncRes = myFunction(a, b); // call func - name(args)
}

int myFunction(int arg1, int arg2) // func implementation - type name(args) {return type}
{
	int myFuncVar = arg1 + arg2;
	return myFuncVar; // returns if type not void
}

/*********/
/* Scope */
/*********/

// Global scope - var available everywhere
int myGlobalVar;

void Scope()
{
	// Local scope - var available only between brackets
	int myFuncLocalVar;
	{
		int mylocalVar;
	}
}

void Enums()
{
	enum MyEnum
	{
		Val,
		Val2,
		Val3
	};
}

void Structs()
{
	// struct declaration - struct name {type fields} // final size rel to struct fields
	struct MyStruct 
	{
		int structPropA;
		float structPropB;
		char* structPropC;
		BOOL structPropD;
	};

	// struct exam declaring with init - struct type name = {values}
	struct MyStruct myStructExamWithInit = {1, 2, "string", TRUE};

	myStructExamWithInit.structPropA; // get value of struct field
	myStructExamWithInit.structPropA = 3; // set value to struct field
}
