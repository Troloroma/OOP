#include "Horseman.h"

Horseman::Horseman() { 
	setHp(7); 
	setShield(1); 
	setDamage(2); 
}

void Horseman::attack(Entity* enemy) { 
	addHp(-(dynamic_cast<Player&>(*enemy).getDamage() * (1 - getShield() / 100))); 
};

void Horseman::changeDirection(int iterator) {
	if (iterator % 8 == 0) { setDirection('A'); }
	if (iterator % 8 == 2) { setDirection('W'); }
	if (iterator % 8 == 4) { setDirection('D'); }
	if (iterator % 8 == 6) { setDirection('S'); }
}