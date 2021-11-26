#include "../include/player.h"
#include "../include/item.h"
#include "../include/grid.h"

Player::Player(int x, int y, Field* field, int hp, int attack, int distance) : Creature(x, y, field, hp, attack, distance) {
    attackDistance = distance;
    levelComplete = false;
}

void Player::heal(int addHp){
    healthPoints += addHp;
}

void Player::increaseAttackPoints(int addAttackPoints){
    attackPoints += addAttackPoints;
}

void Player::increaseAttackDistance(int addAttackDistance){
    attackDistance += addAttackDistance;
}

bool Player::isLevelCompleted(){
    return levelComplete;
}

void Player::move(Direction direction){
    int newX = getX();
    int newY = getY();
    if(direction == UP){
        if (newY > 0)
            newY--;
    }
    else if(direction == DOWN){
        if (newY < currField->getHeight() - 1) 
            newY++;
    }
    else if(direction == LEFT){
        if (newX > 0)
            newX--;
    }
    else if(direction == RIGHT){
        if (newX < currField->getWidth() - 1)
            newX++;
    }

    if (newX == getX() && newY == getY())
        return;
    if (currField->getGrid(newX, newY).isPassable() == false)
        return;
    if (currField->getGrid(newX, newY).isFreeGrid() == false)
        if (currField->getGrid(newX, newY).getEntity().getEntityType() == CREATURE){
            return;
        } else if (currField->getGrid(newX, newY).getEntity().getEntityType() == ITEM) {
            Item& item = static_cast<Item&>(currField->getGrid(newX, newY).getEntity());
            item.effect(*this);
        }

    entityMove(newX, newY);
    if (currField->getGrid(newX, newY).getTypeOfGrid() == Grid::END){
        levelComplete = true;
    }
}

void Player::attack(Direction direction){
    int x;
    int y;
    int i;
    switch (direction){
        case UP:
        i = 1;
        x = getX();
        y = getY();
        while (y - i >= 0 && i <= attackDistance){
            if (currField->getGrid(x, y - i).isFreeGrid() == false)
                if (currField->getGrid(x, y - i).getEntity().getEntityType() == CREATURE)
                    static_cast<Creature&>(currField->getGrid(x, y - i).getEntity()).getDamage(attackPoints);
            i++;
        }
        break;
        case DOWN:
        i = 1;
        x = getX();
        y = getY();
        
        while (y + i < currField->getHeight() && i <= attackDistance){
            if (currField->getGrid(x, y + i).isFreeGrid() == false)
                if (currField->getGrid(x, y + i).getEntity().getEntityType() == CREATURE)
                    static_cast<Creature&>(currField->getGrid(x, y + i).getEntity()).getDamage(attackPoints);
            i++;
        }
        break;
        case RIGHT:
        i = 1;
        x = getX();
        y = getY();
        while (x + i < currField->getWidth() && i <= attackDistance){
            if (currField->getGrid(x + i, y).isFreeGrid() == false)
                if (currField->getGrid(x + i, y).getEntity().getEntityType() == CREATURE)
                    static_cast<Creature&>(currField->getGrid(x + i, y).getEntity()).getDamage(attackPoints);
            i++;
        }
        break;
        case LEFT:
        i = 1;
        x = getX();
        y = getY();
        while (x - i >= 0 && i <= attackDistance){
            if (currField->getGrid(x - i, y).isFreeGrid() == false)
                if (currField->getGrid(x - i, y).getEntity().getEntityType() == CREATURE)
                    static_cast<Creature&>(currField->getGrid(x - i, y).getEntity()).getDamage(attackPoints);
            i++;
        }
    }
}