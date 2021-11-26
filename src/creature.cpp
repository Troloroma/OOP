#include "../include/creature.h"

Creature::Creature(int x, int y, Field* field, int hp, int attack, int dist): 
    GridEntity(x, y, field) 
    {
    entityType = CREATURE;
    attackPoints = attack;
    healthPoints = hp;
    attackDistance = dist;
}

void Creature::getDamage(int damage){
    healthPoints -= damage;
    if (healthPoints <= 0)
        destroy();
}

int Creature::getHp(){
    return healthPoints;
}