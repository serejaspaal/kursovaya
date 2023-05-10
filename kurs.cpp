#include "game.h"

int main()
{
    system("stty -icanon -echo");
    Game game;
    game.run();
    system("stty icanon echo");
    return 0;
}