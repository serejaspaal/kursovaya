// check_functions.cpp
#include "check_functions.h"

// check row
bool check_row_creation(int x, int y, int s[])
{
    for (int i = 0; i < y; i++)
        if (s[x * 9 + i] == s[x * 9 + y])
            return false;

    return true;
}

// check column
bool check_column_creation(int x, int y, int s[])
{
    for (int i = 0; i < x; i++)
        if (s[i * 9 + y] == s[x * 9 + y])
            return false;

    return true;
}

// check square
bool check_square_creation(int x, int y, int s[])
{
    int i_start = x / 3;      i_start *= 3;
    int j_start = y / 3;      j_start *= 3;

    for (int i = i_start; i < i_start + 3; i++)
        for (int j = j_start; j < j_start + 3; j++)
        {
            if (i == x && j == y)
                return true;

            if (s[i * 9 + j] == s[x * 9 + y])
                return false;
        }
    return true;
}
