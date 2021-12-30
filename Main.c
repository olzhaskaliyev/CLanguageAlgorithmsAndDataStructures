#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "CLanguage.h"

// Main program execution function
int main(int argc, char *argv[]) // args passes on program launch (program.exe -argc=argv)
{
	srand(time(NULL)); // set global random seed to current time
	
	// C Language
	VariablesAndConstants();
	Scope();
	DataTypes();
	Operators();
	ConditionalsAndLoops();
	Functions();
	StaticArrays();
	Pointers();
	MemoryAllocation();
	DynamicArrays();
	// Strings();
	// Enums();
	// Structs();
	// Unions();

	// Data Structures
	// List();
	// Stack();
	// Queue();
	// Heap();
	// Tree();
	
	// Algorithms
	// Sort();
	// Search();

	return 0; // required, because in several compilers throw error
}
