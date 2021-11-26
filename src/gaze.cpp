#include "../include/gaze.h"

Gaze::Gaze(int x, int y, Field *field) : Item(x, y, field) {}

void Gaze::effect(Player &player){
    player.increaseAttackDistance(1);
    destroy();
}