

#include "game.h"

void Game::run()
{
    Keyboard key;
    Cursor cur;
    clrscr();
    cur.gotoxy(28, 7);
    printf("SUDOKU\n");
    usleep(2000000);
    clrscr();
    cur.gotoxy(0, 0);
    system("stty icanon echo");
    Map map;
    system("stty -icanon -echo");
    map.initMask();
    map.initDigits();
    map.show();
    cur.gotoxy(1, 1);
    do
    {
        key.takeKey();
        switch (key.getKey())
        {
        case 67:
            cur.goRight();
            break;
        case 68:
            cur.goLeft();
            break;
        case 65:
            cur.goUp();
            break;
        case 66:
            cur.goDown();
            break;
        case 49:
            map.setDigit(cur.getX(), cur.getY(), 1);
            break;
        case 50:
            map.setDigit(cur.getX(), cur.getY(), 2);
            break;
        case 51:
            map.setDigit(cur.getX(), cur.getY(), 3);
            break;
        case 52:
            map.setDigit(cur.getX(), cur.getY(), 4);
            break;
        case 53:
            map.setDigit(cur.getX(), cur.getY(), 5);
            break;
        case 54:
            map.setDigit(cur.getX(), cur.getY(), 6);
            break;
        case 55:
            map.setDigit(cur.getX(), cur.getY(), 7);
            break;
        case 56:
            map.setDigit(cur.getX(), cur.getY(), 8);
            break;
        case 57:
            map.setDigit(cur.getX(), cur.getY(), 9);
            break;
        case 127:
            map.setDigit(cur.getX(), cur.getY(), 0);
            break;
        case 48:
            map.setDigit(cur.getX(), cur.getY(), 0);
            break;
        case 32:
            if (map.check_done())
            {
                goto win;
            }
            break;
        }

        cur.gotoxy(cur.getX(), cur.getY());
    } while (key.getKey() != 9);
win:
    clrscr();
}
