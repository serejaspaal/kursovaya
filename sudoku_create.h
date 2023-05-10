// sudoku_create.h

#ifndef ZCREATE
#define ZCREATE

#include <ctime>
#include <cstdlib>
#include "check_functions.h"
#include "difficulty.h"

extern int s1d[81];
extern int sudoku[9][9];
bool test(int, int);
bool check_repeated(int i, int j);
void move_back(int& i, int& j);
void write(int i, int j);
void sudoku_create_func();

#endif
