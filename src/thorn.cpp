#include "../include/thorn.h"

Thorn::Thorn(int x, int y, Field *field) : Item(x, y, field){}

void Thorn::effect(Player &player){
    player.getDamage(10);
}