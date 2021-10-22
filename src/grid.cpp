#include "../include/grid.h"

Grid::Grid(int x, int y, Type type):
    x(x),
    y(y),
    type(type){
        passable = (type != BORDER);
        setValue(type);
    }

Grid::Grid(){
    };

int Grid::getX(){
    return x;
}

int Grid::getY(){
    return y;
}

char Grid::getValue(){
    return value;
}

Grid::Type Grid::getTypeOfGrid(){
    return type;
}

void Grid::setValue(Type type){
    if (type == BORDER)
        value = '#';
    else if (type == START)
        value = 'S';
    else if (type == END)
        value = 'E';
    else 
        value = '_';
}

void Grid::setTypeOfGrid(Type type){
    this->type = type;
}

bool Grid::isPassable(){
    return passable;
}