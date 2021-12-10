#include "Wolf.h"

Wolf::Wolf() { 
	setHp(10); 
	setShield(2); 
	setDamage(3); 
}

void Wolf::attack(Entity* enemy) { 
	addHp(-(dynamic_cast<Player&>(*enemy).getDamage() * (1 - getShield() / 100))); 
};

void Wolf::changeDirection(int iterator) {
	if (iterator % 12 == 0) { setDirection('D'); }
	if (iterator % 12 == 3) { setDirection('W'); }
	if (iterator % 12 == 6) { setDirection('A'); }
	if (iterator % 12 == 9) { setDirection('S'); }
}