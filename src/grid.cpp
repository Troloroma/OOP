#include "../include/grid.h"

Grid::Grid(int x, int y, int type):
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

int Grid::getItem(){
    //returns item
    return 0;
}

int Grid::getTypeOfGrid(){
    return type;
}

void Grid::setValue(int type){
    if (type == BORDER)
        value = '#';
    else if (type == START)
        value = 'S';
    else if (type == END)
        value = 'E';
    else 
        value = '_';
}

bool Grid::isPassable(){
    return passable;
}