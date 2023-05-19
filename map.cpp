#include "map.h"

#define clrscr() printf("\e[2J");

Map::Map()
{
    sudoku_create_func();
}

void Map::initMask()
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((i == 0) || (i == SIZE - 1) || (i == 4) || (i == 8) || (j == 0) || (j == SIZE - 1) || (j == 4) || (j == 8))
            {
                mask[i][j] = 1;
            }
            else if (sudoku[x][y] != 0)
            {
                mask[i][j] = 1;
                if (x == 8)
                {
                    x = 0;
                    y++;
                }
                else
                    x++;
            }
            else
            {
                mask[i][j] = 0;
                if (x == 8)
                {
                    x = 0;
                    y++;
                }
                else
                    x++;
            }
        }
    }
}

void Map::initDigits()
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((i == 0) || (i == SIZE - 1) || (i == 4) || (i == 8))
            {
                digits[i][j] = HORI;
            }
            else if ((j == 0) || (j == SIZE - 1) || (j == 4) || (j == 8))
            {
                digits[i][j] = VERTI;
            }
            else
            {
                digits[i][j] = sudoku[x][y];
                if (x == 8)
                {
                    x = 0;
                    y++;
                }
                else
                    x++;
            }
        }
    }
}

void Map::setDigit(int j, int i, int temp)
{

    if (!mask[i][j])
    {
        digits[i][j] = temp;
    }
    show(temp);
}

void Map::show()
{
    Cursor start;
    start.gotoxy(0, 0);
    clrscr();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (digits[i][j] == HORI)
            {
                printf("-");
            }
            else if (digits[i][j] == VERTI)
            {
                printf("|");
            }
            else if (digits[i][j] == 0)
                printf(" ");
            else
            {
                printf("%d", digits[i][j]);
            }
        }
        printf("\n");
    }
    printf("Use Arrows to control your cursor\nPress SPACE if you think you made it\nPress TAB if you want to quit");
}

void Map::show(int num)
{
    Cursor start;
    start.gotoxy(0, 0);
    clrscr();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (digits[i][j] == HORI)
            {
                printf("-");
            }
            else if (digits[i][j] == VERTI)
            {
                printf("|");
            }
            else if (digits[i][j] == 0)
                printf(" ");
            else if (mask[i][j] == 0)
            {
                if ((check_column(i, j)) or (check_square(i, j)) or (check_row(i, j)))
                {
                    printf("\x1B[31m"); // красный включаем
                    printf("%d", digits[i][j]);
                    printf("\x1B[0m"); // красный выключаем
                }
                else
                {
                    printf("\x1B[36m"); // включаем красивый цвет
                    printf("%d", digits[i][j]);
                    printf("\x1B[0m"); // выключаем красивый цвет
                }
            }
            else
            {
                printf("%d", digits[i][j]);
            }
        }
        printf("\n");
    }
    printf("Use Arrows to control your cursor\nPress SPACE if you think you made it\nPress TAB if you want to quit");
}

bool Map::check_column(int x, int y)
{
    bool check = false;
    for (int i = 0; i < 13; i++)
    {
        if (i == y)
            continue;

        if (digits[x][i] == digits[x][y])
            check = true;
    }
    return check;
}

bool Map::check_row(int x, int y)
{
    bool check = false;
    for (int i = 0; i < 13; i++)
    {
        if (i == x)
            continue;

        if (digits[i][y] == digits[x][y])
            check = true;
    }

    return check;
}

bool Map::check_square(int x, int y)
{
    int i_start, j_start;
    if (x < 4)
        i_start = 1;
    else if (x < 8)
        i_start = 5;
    else
        i_start = 9;
    if (y < 4)
        j_start = 1;
    else if (y < 8)
        j_start = 5;
    else
        j_start = 9;
    bool check = false;
    for (int i = i_start; i < i_start + 3; i++)
        for (int j = j_start; j < j_start + 3; j++)
        {
            if (i == x && j == y)
                continue;

            if (digits[i][j] == digits[x][y])
                check = true;
        }
    return check;
}

bool Map::check_done()
{
    bool endcheck = true;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (mask[i][j] == 0)
            {
                if ((check_column(i, j)) or (check_row(i, j)) or (check_square(i, j)))
                {
                    endcheck = false;
                    break;
                }
            }
        }
        if (!endcheck)
            break;
    }
    if (endcheck)
    {
        Cursor happy;
        happy.gotoxy(30, 18);
        printf("NICE JOB!!!\nPress any button to quit");
        getchar();
    }
    else
    {
        clrscr();
        Cursor sad;
        sad.gotoxy(30, 12);
        printf("we are not done");
        getchar();
        show();
    }
    return endcheck;
}