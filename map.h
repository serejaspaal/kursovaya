#ifndef MAP__
#define MAP__

#include "sudoku_create.h"
#include "user.h"
class Map

{
private:
    const int SIZE = 13;
    const int HORI = 10;
    const int VERTI = 20;
    int digits[13][13];
    bool mask[13][13];

public:
    Map();

    void initMask();

    void initDigits();

    void setDigit(int j, int i, int temp);

    void show();

    void show(int num);

    bool check_column(int x, int y);

    bool check_row(int x, int y);

    bool check_square(int x, int y);

    bool check_done();
};

#endif