#include "Knight.h"

Knight::Knight() { 
	setHp(4); 
	setShield(0); 
	setDamage(1); 
}

void Knight::attack(Entity* enemy) { 
	addHp(-(dynamic_cast<Player&>(*enemy).getDamage() * (1 - getShield() / 100))); 
};

void Knight::changeDirection(int iter) {
	if (iter % 4 == 0) { setDirection('W'); }
	if (iter % 4 == 1) { setDirection('A'); }
	if (iter % 4 == 2) { setDirection('S'); }
	if (iter % 4 == 3) { setDirection('D'); }
}
