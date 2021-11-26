#include "../include/wolf.h"

Wolf::Wolf(int x, int y, Field *field, int hp, int attack, int distance) : EnemyController(x, y, field, hp, attack, distance){
    trajectory = {UP, UP, RIGHT, DOWN, DOWN, RIGHT, UP, UP, LEFT, DOWN, DOWN, LEFT};
}

bool Wolf::isPlayerReachable(Player &player){
    if (abs(getX() - player.getX()) <= attackDistance && abs(getY() - player.getY()) <= attackDistance)
        return true;
    else 
        return false;
}

void Wolf::attack(Player& player){
    player.getDamage(attackPoints);
}

void Wolf::nextAction(Player& player){
    if (isPlayerReachable(player)){
        attack(player);
    } else {
        move(trajectory[directionIndex]);
        increaseIndex();
    }
}

void Wolf::move(Direction direction){
    int newX = getX();
    int newY = getY();
    switch(direction){
        case UP:
            if (newY - 1 >= 0){
                if (currField->getGrid(newX, newY - 1).isFreeGrid() && currField->getGrid(newX, newY - 1).isPassable()){
                    newY--;
                }
            }
            break;
        case DOWN:
            if (newY + 1 < currField->getHeight()){
                if (currField->getGrid(newX, newY + 1).isFreeGrid() && currField->getGrid(newX, newY + 1).isPassable()){
                    newY++;
                }
            }
            break;
        case LEFT:
            if (newX - 1 >= 0){
                if (currField->getGrid(newX - 1, newY).isFreeGrid() && currField->getGrid(newX - 1, newY).isPassable()){
                    newX = newX - 2;
                }
            }
            break;
        case RIGHT:
            if (newX + 1 < currField->getWidth()){
                if (currField->getGrid(newX + 1, newY).isFreeGrid() && currField->getGrid(newX + 1, newY).isPassable()){
                    newX = newX + 2;
                }
            } 
            break;
        
    }
    if (newX == getX() && newY == getY())
        return;
    entityMove(newX, newY);
}