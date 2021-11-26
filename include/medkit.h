#pragma once
#include "item.h"

class Medkit : public Item{
public:
    Medkit(int, int, Field*);
    void effect(Player &);
};