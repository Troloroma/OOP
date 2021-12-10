#pragma once
#include <string>
#include <iostream>
#include"../Entity/Entity.h"


class Grid {
private:
	Entity* entity = nullptr;
	int x;
	int y;
	std::string Type;
public:
	Grid();
	Grid(int x, int y, std::string typeGrid);
	Entity* getEntity();
	void setEntity(Entity* val);
	std::string getType();
	void setType(std::string val);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
};
