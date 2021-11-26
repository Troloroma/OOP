#include "../include/knight.h"

Knight::Knight(int x, int y, Field *field, int hp, int attack, int distance) : EnemyController(x, y, field, hp, attack, distance){
    trajectory = {RIGHT, RIGHT, RIGHT, LEFT, LEFT, LEFT};
}

bool Knight::isPlayerReachable(Player &player){
    if (abs(getX() - player.getX()) <= attackDistance && abs(getY() - player.getY()) <= attackDistance)
        return true;
    else 
        return false;
}

void Knight::attack(Player& player){
    player.getDamage(attackPoints);
}

void Knight::nextAction(Player& player){
    if (isPlayerReachable(player)){
        attack(player);
    } else {
        move(trajectory[directionIndex]);
        increaseIndex();
    }
}

void Knight::move(Direction direction){
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
                    newX--;
                }
            }
            break;
        case RIGHT:
            if (newX + 1 < currField->getWidth()){
                if (currField->getGrid(newX + 1, newY).isFreeGrid() && currField->getGrid(newX + 1, newY).isPassable()){
                    newX++;
                }
            } 
            break;
        
    }
    if (newX == getX() && newY == getY())
        return;
    entityMove(newX, newY);
}