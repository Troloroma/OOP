#include "../include/EnemyController.h"

void EnemyController::increaseIndex(){
    if (directionIndex != trajectory.size() - 1){
        directionIndex++;
    } else {
        directionIndex = 0;
    }
}

EnemyController::EnemyController(int x, int y, Field* field, int hp, int attack, int distance) : Creature(x, y, field, hp, attack, distance) {
    directionIndex = 0;
}