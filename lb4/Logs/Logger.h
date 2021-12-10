#pragma once

#include <map>
#include "../Game/Entity/Entity.h"
#include "../Game/Objects/Grid.h"
#include "../Game/Entity/Player.h"
#include "../Game/Entity/Enemies/Knight.h"
#include "../Game/Entity/Enemies/Horseman.h"
#include "../Game/Entity/Enemies/Wolf.h"
#include <vector>


class Logger {
public:
	void clonePlayer();
	void cloneEnemy(Entity* enemy);
	std::vector <int> playerStats = {0, 0, 0};
	Entity* player_ = nullptr;
	std::map <Entity*, std::vector <int>> enemyStats;
	Logger() = default;
	Logger(Entity* hero, std::vector <Grid*> enemies);
};