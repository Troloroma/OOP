#pragma once
#include "IEnemy.h"
#include "creature.h"

class Archer : public Creature, public IEnemy{
public:
    Archer(int, int, Field*, int hp, int attack, int distance);
    void nextAction(Player &);
    bool isPlayerReachable(Player &);
    void attack(Player &);
};