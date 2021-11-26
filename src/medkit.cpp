#include "../include/medkit.h"

Medkit::Medkit(int x, int y, Field* field) : Item(x, y, field){}

void Medkit::effect(Player &player){
    player.heal(20);
    destroy();
}   