#pragma once
#include "item.h"

class Power : public Item{   //увеличение силы атаки персонажа)
public:
    Power(int, int, Field *);
    void effect(Player &);
};