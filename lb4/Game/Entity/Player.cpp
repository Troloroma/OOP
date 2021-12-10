#include "Player.h"


Player::Player() { setShield(2); setHp(10); setDamage(3); }

const int Player::getShield() const {
	return this->shield;
}
void Player::setShield(int val) {
	this->shield = val;
}
const int Player::getHp() const {
	return this->hp;
}
void Player::setHp(int val) {
	this->hp = val;
}
const int Player::getDamage() const {
	return this->damage;
}
void Player::setDamage(int val) {
	this->damage = val;
}
void Player::addShield(int val) {
	this->shield += val;
}
void Player::addHp(int val) {
	this->hp += val;
}
void Player::addDamage(int val) {
	this->damage += val;
}
void Player::attack(Entity* enemy) {
	addHp(-(dynamic_cast<Enemy&>(*enemy).getDamage() * (1 - getShield() / 100)));
};
void Player::takeItem(Entity* item) {
	if (typeid(*item).name() == typeid(Medkit).name()) {
		addHp(dynamic_cast<Item&>(*item).getValue());
	}
	if (typeid(*item).name() == typeid(Shield).name()) {
		addShield(dynamic_cast<Item&>(*item).getValue());
	}
	if (typeid(*item).name() == typeid(Power).name()) {
		addDamage(dynamic_cast<Item&>(*item).getValue());
	}
};

std::ostream& operator<<(std::ostream& out, const Player& mainPlayer) {
	std::string text = "\nPlayer info: \nHp: " + std::to_string(mainPlayer.getHp()) + "\nDamage: " + std::to_string(mainPlayer.getDamage()) + "\nShield: " + std::to_string(mainPlayer.getShield()) + '\n';
	out << text;
	return out;
}