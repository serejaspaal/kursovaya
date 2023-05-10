// sudoku_create.cpp
#include "sudoku_create.h"

// ARRAY DECLARATIONS
int sudoku[9][9];
int s1d[81];
int test_array[9 * 9][9] = { 0 };


// THE THING
void sudoku_create_func()
{
    srand(time(0));

    int difficulty = difficulty_input();

// CREATION PART ////////////////////////////////////////////////////////////
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            for (;;)
            {
                if (!test(i, j))
                    move_back(i, j);
                s1d[i * 9 + j] = sudoku[i][j] = rand() % 9 + 1;
                if (check_repeated(i, j))
                    continue;
                write(i, j);
                if (check_square_creation(i, j, s1d) && check_row_creation(i, j, s1d) && check_column_creation(i, j, s1d))
                    break;
            }
        }
    }
//////////////////////////////////////////////////////////////////////////////


// ERASING PART /////////////////////////// 
    for (int q = difficulty * 11; q > 0; q--) {
        i = rand() % 9;
        j = rand() % 9;
        if (s1d[i * 9 + j] == 0)
            q++;
        s1d[i * 9 + j] = sudoku[i][j] = 0;
    }
//////////////////////////////////////////

   // print(s1d);
        
}


////////////////// TEST FUNCTIONS: /////////////////////
bool test(int i, int j)
{
    int current = i * 9 + j + 1;

    for (int x = 1; x < 9; x++)
        if (test_array[current][x] == 0)
            return true;

    return false;
}

bool check_repeated(int i, int j)
{
    int value = sudoku[i][j];
    int current = i * 9 + j + 1;

    if (test_array[current][value] == 1)
        return true;
    else
        return false;
}

void move_back(int& i, int& j)
{
    int current = i * 9 + j + 1;

    for (int x = 1; x <= 9; x++)
        test_array[current][x] = 0;

    if (j < 1)
    {
        i--;
        j = 8;
    }
    else
        j--;
}

void write(int i, int j)
{
    int current = i * 9 + j + 1;
    int value = sudoku[i][j];
    test_array[current][value] = 1;
}
////////////////////////////////////////////////////////

