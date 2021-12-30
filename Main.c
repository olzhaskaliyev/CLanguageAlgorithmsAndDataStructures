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
	DataTypes();
	Operators();
	ConditionalsAndLoops();
	StaticArrays();
	Pointers();
	MemoryAllocation();
	DynamicArrays();
	Strings();
	Functions();
	Scope();
	Enums();
	Structs();

	return 0; // required, because in several compilers throw error
}
