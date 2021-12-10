#pragma once
#include "../movableEntity.h"
#include "../Player.h"


class Enemy : public movableEntity {
private:
	char direction = 'W';
public:
	const char getDirection() const;
	const int getShield() const;
	const int getHp() const;
	const int getDamage() const;
	void setDirection(char val);
	void setShield(int val);
	void setHp(int val);
	void setDamage(int val);
	void addHp(int val);
	friend std::ostream& operator<<(std::ostream& out, const Enemy& enemy);
};