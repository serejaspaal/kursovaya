#include "user.h"


Cursor::Cursor()
{
    x = 1;
    y = 1;
}

void Cursor::gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y + 1, x + 1);
}

int Cursor::getX()
{
    return x;
}

int Cursor::getY()
{
    return y;
}

void Cursor::goLeft()
{
    if (x == 1)
    {
        x = 12;
    }
    else if (x == 5 || x == 9)
    {
        x--;
    }
    x--;
}

void Cursor::goRight()
{
    if (x == 11)
    {
        x = 0;
    }
    else if (x == 3 || x == 7)
    {
        x++;
    }
    x++;
}

void Cursor::goUp()
{
    if (y == 1)
    {
        y = 12;
    }
    else if (y == 5 || y == 9)
    {
        y--;
    }
    y--;
}

void Cursor::goDown()
{
    if (y == 11)
    {
        y = 0;
    }
    else if (y == 3 || y == 7)
    {
        y++;
    }
    y++;
}

    Keyboard::Keyboard()
    {
    }

void Keyboard::takeKey()
{
    do
    {
        ch = getchar();
    } while ((ch == 27) || (ch == 91));
}

int Keyboard::getKey()
{
    return ch;
}