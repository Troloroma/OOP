#pragma once

#include "movableEntity.h"
#include "Items/Item.h"
#include "Items/Medkit.h"
#include "Items/Power.h"
#include "Items/Shield.h"
#include "Enemies/Enemy.h"

class Player : public movableEntity {
public:
	Player();
	void attack(Entity* enemy);
	void takeItem(Entity* item);
	const int getShield() const;
	const int getHp() const;
	const int getDamage() const;
	void setHp(int val);
	void setShield(int val);
	void setDamage(int val);
	void addShield(int val);
	void addHp(int val);
	void addDamage(int val);
	friend std::ostream& operator<<(std::ostream& out, const Player& MainHero);
};