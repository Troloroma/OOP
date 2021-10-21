using namespace std;
#pragma once
#include "field.h"

class Game{
private:
    Field *field;
public:
    Game(int, int);
    ~Game();
    void runGame(int x, int y);
};