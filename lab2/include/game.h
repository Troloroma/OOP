using namespace std;
#pragma once

#include "draw.h"

class Game{
private:
    Field *field;
    Draw drawer;
public:
    Game(int, int);
    ~Game();
    void runGame(int x, int y);
};