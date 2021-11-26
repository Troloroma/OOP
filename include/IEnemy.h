#pragma once
#include "player.h"

class IEnemy{
public:
    virtual bool isPlayerReachable(Player &player) = 0;
    virtual void attack(Player &player) = 0;
    virtual void nextAction(Player &player) = 0;
};