#pragma once
#include <vector>
#include "IMove.h"
#include "creature.h"

class EnemyController : public Creature{
public:
    EnemyController(int, int, Field*, int hp, int attack, int distance);
protected:
    int directionIndex;
    void increaseIndex();
    std::vector<Direction> trajectory;   
};