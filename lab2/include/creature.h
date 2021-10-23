#pragma once
#include "GridEntity.h"

class Creature : public GridEntity{
public:
    Creature(int given_x, int given_y, Field* field, int hp, int attack, int range);
    int getHp();
    void getDamage(int);
protected:
    int attackPoints;
    int attackDistance;
    int healthPoints;
};