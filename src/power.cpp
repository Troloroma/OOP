#include "../include/power.h"

Power::Power(int x, int y, Field *field) : Item(x, y, field) {} //увеличение силы атаки

void Power::effect(Player &player){
    player.increaseAttackPoints(10);
    destroy();
}