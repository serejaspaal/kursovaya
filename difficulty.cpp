// difficulty.cpp
#include "difficulty.h"
#include <iostream>

int difficulty_input()
{
    std::cout << "Choose difficulty (1-5): ";
    int value;
    std::cin >> value;
    while (std::cin.fail() or value < 1 or value > 5)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Try again: ";
        std::cin >> value;
    }
    return value;
}
