#include <iostream>
using namespace std;
#pragma once
#include "../include/GridEntity.h"

class Grid{
private:
    //GridEntity entity;
    int x = 0;
    int y = 0;
    bool passable;
    char value = '_';
public:
    enum Type {BORDER, START, END, EMPTY};
    Type type;
    Grid();
    Grid(int x, int y, Type type);
    int getX();
    int getY();
    Type getTypeOfGrid();
    void setTypeOfGrid(Type type);
    void setValue(Type type);
    bool isPassable();
    char getValue();
};