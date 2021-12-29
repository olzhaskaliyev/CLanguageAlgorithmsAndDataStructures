#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "CLanguage.h"
#include "Utilities.h"
#include "Programs.h"

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
	Functions();
	PointersAndMemoryAllocation();
	DynamicArrays();
	Strings();
	Enums();
	Structs();
	Scope();

	randomArray();

	return 0; // required, because in several compilers throw error
}
