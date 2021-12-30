#pragma once

int i = 0;
int a = 1;
int b = 2;
int* ptr = &a;
#define expression (a + b)
#define expressionResA (2)
#define expressionResB (3)
#define condition (a > b)
#define statement (a = 1)
#define statementA (a = 2)
#define statementB (b = 1)
#define ARR_ROWS 5
#define ARR_COLS 8
#define ARR_PAGES 3

void fillArray(float*, int);
void fill2DArray(float**, int, int);
void fill3DArray(float***, int, int, int);
void printArray(float*, int);
void print2DArray(float**, int, int);
void print3DArray(float***, int, int, int);

float getRandomNumber(float, float, int);
void fillArrayRandom(float*, int, float, float, int);
