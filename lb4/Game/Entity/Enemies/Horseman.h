#pragma once
#include "Enemy.h"


class Horseman : public Enemy {
public:
	Horseman();
	void attack(Entity* enemy);
	void changeDirection(int);
};