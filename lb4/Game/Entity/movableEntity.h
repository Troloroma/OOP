#pragma once
#include "Entity.h"


class movableEntity : public Entity {
protected:
	int shield;
	int hp;
	int damage;
public:
	virtual const int getShield() const = 0;
	virtual const int getDamage() const = 0;
	virtual const int getHp() const = 0;
	
	virtual void setShield(int val) = 0;
	virtual void setHp(int val) = 0;
	virtual void setDamage(int val) = 0;
	virtual void addHp(int val) = 0;
	virtual void attack(Entity* enemy) = 0;
};