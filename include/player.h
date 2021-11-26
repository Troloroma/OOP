#pragma once
#include "IMove.h"
#include "creature.h"

class Player : public IMove, public Creature{
    bool levelComplete;
public:
    Player(int x, int y, Field* field, int hp, int attack, int distance);
    void move(Direction direction);
    void attack(Direction direction);
    void heal(int);
    void increaseAttackPoints(int);
    void increaseAttackDistance(int);
    bool isLevelCompleted();
};