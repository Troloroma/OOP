#pragma once
#include "Enemy.h"


class Wolf : public Enemy {
public:
	Wolf();
	void attack(Entity* enemy);
	void changeDirection(int);
};