#pragma once
#include "item.h"

class Thorn : Item{ //шипы
    Thorn(int, int, Field *field);
    void effect(Player &);
};