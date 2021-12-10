#pragma once
#include "Enemy.h"

class Knight : public Enemy {
public:
	Knight();
	void attack(Entity* enemy);
	void changeDirection(int);
};