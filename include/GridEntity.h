#pragma once
#include "field.h"
class Field;
class GridEntity{
protected:
    bool alive;
    void destroy(); 
    int x;
    int y;
    Field *currField;
public:
    GridEntity(int newX, int newY, Field *field);
    void entityMove(int, int);
    int getX();
    int getY();
    bool isAlive();
    enum EntityType{CREATURE, ITEM};
    EntityType getEntityType();
    EntityType entityType;
    virtual ~GridEntity() = default;
}; 