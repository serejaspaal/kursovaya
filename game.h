#ifndef GAMELANCH__
#define GAMELANCH__

#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include "map.h"

#define clrscr() printf("\e[2J");


class Game
{
public:
    void run();
};

#endif