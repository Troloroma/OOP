#include "../include/GridEntity.h"
#include "../include/field.h"

GridEntity::GridEntity(int x, int y, Field *field): 
    x(x), 
    y(y), 
    currField(field)
    {
    alive = true;
}

int GridEntity::getX(){
    return x;
}

int GridEntity::getY(){
    return y;
}
GridEntity::EntityType GridEntity::getEntityType(){
    return entityType;
}

void GridEntity::entityMove(int newX, int newY){
    currField->getGrid(x, y).removeEntity();
    currField->getGrid(newX, newY).setEntity(this);
    x = newX;
    y = newY;
}

void GridEntity::death(){
    alive = false;
    currField->getGrid(x, y).removeEntity();
}