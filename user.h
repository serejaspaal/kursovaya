#ifndef CONTROLS__
#define CONTROLS__

class Cursor
{
private:
    int x, y;

public:
    Cursor();

    void gotoxy(int x, int y);

    int getX();
    
    int getY();

    void goLeft();

    void goRight();

    void goUp();

    void goDown();
};

class Keyboard
{
private:
    int ch;

public:
    Keyboard();

    void takeKey();

    int getKey();
};

#endif