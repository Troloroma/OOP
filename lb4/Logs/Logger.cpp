#include "Logger.h"

Logger::Logger(Entity * player, std::vector <Grid*> enemies){
	player_ = player;
	clonePlayer();
	for (int i = 0; i < enemies.size(); i++) {
		enemyStats.insert(std::pair<Entity*, std::vector<int>>(enemies[i]->getEntity(), { 0, 0, 0 }));
		cloneEnemy(enemies[i]->getEntity());
	}
}

void Logger::cloneEnemy(Entity* enemy) {
	enemyStats[enemy][0] = (dynamic_cast<Enemy&>(*enemy)).getHp();
	enemyStats[enemy][1] = (dynamic_cast<Enemy&>(*enemy)).getDamage();
	enemyStats[enemy][2] = (dynamic_cast<Enemy&>(*enemy)).getShield();
}

void Logger::clonePlayer() {
	playerStats[0] = (dynamic_cast<Player&>(*player_)).getHp();
	playerStats[1] = (dynamic_cast<Player&>(*player_)).getDamage();
	playerStats[2] = (dynamic_cast<Player&>(*player_)).getShield();
}