#pragma once
#include "player.h"

class Item : public GridEntity{
public:
    virtual void effect(Player& player) = 0;
    Item(int, int, Field*);
};