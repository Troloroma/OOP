#include "../include/archer.h"

Archer::Archer(int x, int y, Field *field, int hp, int attack, int distance) : Creature(x, y, field, hp, attack, distance) {}

bool Archer::isPlayerReachable(Player &player){
    if (abs(this->getX() - player.getX()) <= attackDistance && abs(this->getY() - player.getX()) <= attackDistance)
        return true;
    else 
        return false;
    
}

void Archer::attack(Player &player){
    player.getDamage(attackPoints); 
}

void Archer::nextAction(Player &player){
    if (isPlayerReachable(player))
        attack(player);
}

