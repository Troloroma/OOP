#pragma once
#include "IEnemy.h"
#include "IMove.h"
#include "EnemyController.h"

class Wolf : public EnemyController, public IMove, public IEnemy {
public:
    Wolf(int x, int y, Field* field, int hp, int attack, int distance);
    void move(Direction direction);
    void attack(Player& player);
    bool isPlayerReachable(Player &player);
    void nextAction(Player& player);
};