#include "Enemy.h"


const char Enemy::getDirection() const {
	return this->direction;
}


void Enemy::setDirection(char val){
	this->direction = val;
}


const int Enemy::getShield() const {
	return this->shield;
}
void Enemy::setShield(int val) {
	this->shield = val;
}
const int Enemy::getHp() const {
	return this->hp;
}
void Enemy::setHp(int val) {
	this->hp = val;
}
const int Enemy::getDamage() const {
	return this->damage;
}
void Enemy::setDamage(int val) {
	this->damage = val;
}
void Enemy::addHp(int val) {
	this->hp += val;
}

std::ostream& operator<<(std::ostream& out, const Enemy& enemy) {
	std::string text = "\nEnemy info: \nHp: " + std::to_string(enemy.getHp()) + "\nDamage: " + std::to_string(enemy.getDamage()) + "\nShield: " + std::to_string(enemy.getShield()) + '\n';
	out << text;
	return out;
}