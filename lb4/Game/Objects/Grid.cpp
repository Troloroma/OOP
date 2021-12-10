#include "Grid.h"

Grid::Grid() { 
	Type = "EMPTY"; 
	x = 0; 
	y = 0; 
	entity = nullptr; 
}

Grid::Grid(int x, int y, std::string typeCell) {
	this->x = x;
	this->y = y;
	this->Type = typeCell;
}

void Grid::setX(int val) { this->x = val; }

void Grid::setY(int val) { this->y = val; }

int Grid::getX() { return this->x; }

int Grid::getY() { return this->y; }

std::string Grid::getType() { return this->Type;}

void Grid::setType(std::string val) { this->Type = val; }

void Grid::setEntity(Entity* val) { this->entity = val; }

Entity* Grid::getEntity() { if (this != nullptr) { return entity; } return 0;}