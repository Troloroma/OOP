#pragma once

#include <vector>
#include "Grid.h"
#include "../Entity/Entity.h"
#include "../Entity/Player.h"
#include "../Entity/Items/Item.h"
#include "../Entity/Enemies/Knight.h"
#include "../Entity/Enemies/Horseman.h"
#include "../Entity/Enemies/Wolf.h"

class Field {
private:
	int width;
	int height;
	int startEnemiesAmount = 0;
	Grid* enter;
	Grid* exit;
	Grid* player;
	void playerSpawn();
	void bordersSpawn();
	void startFinishGeneraton();
	void enemiesGeneration();
	void itemsGeneration();
public:
	Field();
	Grid** board;
	std::vector <Grid*> enemies;
	Grid* getEnter();
	Grid* getExit();
	Grid* getPlayer();
	int getWidth();
	int getHeight();
	void setWidth(int value);
	void setHeight(int value);
	int getEnemyInd(Grid* obj);
	void setEnter(Grid* obj);
	void setExit(Grid* obj);
	void setPlayer(Grid* obj);
	void moveEntity(Grid grid, char dir, int enemyCount = 0);
	int getStartEnemiesAmount();
	Field(int, int);
	Field(const Field& obj);
	Field& operator=(const Field& obj);
	Field(Field&& obj);
	Field& operator=(Field&& obj);
	~Field();
};