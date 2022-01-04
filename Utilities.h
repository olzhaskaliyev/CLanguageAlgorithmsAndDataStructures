#pragma once

extern int i;
extern int a;
extern int b;
extern int* ptr;
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

inline float getRandomNumber(float, float, int);
long double inputNumber(char*);

inline float* initArray(int);
float** init2DArray(int, int);
float*** init3DArray(int, int, int);
void fillArrayRandomly(float*, int, float, float, int);
void fill2DArrayRandomly(float**, int, int, float, float, int);
void fill3DArrayRandomly(float***, int, int, int, float, float, int);
void printArray(float*, int);
void print2DArray(float**, int, int);
void print3DArray(float***, int, int, int);
void free2DArray(float**, int);
void free3DArray(float***, int, int);
