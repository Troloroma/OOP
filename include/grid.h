#include <iostream>
using namespace std;
#pragma once
#include "grid_type.h"
#include "../include/GridEntity.h"

class Grid{
private:
    GridEntity entity;
    int x = 0;
    int y = 0;
    int type;
    bool passable;
    char value = '_';
public:
    Grid();
    Grid(int x, int y, int type);
    int getX();
    int getY();
    int getItem();
    int getTypeOfGrid();
    void setValue(int type);
    bool isPassable();
    char getValue();
};