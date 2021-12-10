#include "ConsoleLogger.h"


void ConsoleLogger::writePlayer() {
	std::cout << "\n#player changed#\n\nFrom:\nHp " << (*logger).playerStats[0] << "\nDamage: " << (*logger).playerStats[1] << "\nShield: " << (*logger).playerStats[2] << "\nTo: " << dynamic_cast<Player&>(*(*logger).player_);
}

void ConsoleLogger::writeEnemy(Entity* enemy) {
	std::cout << "\n#enemy changed#\n\nFrom:\nHp: " << (*logger).enemyStats[enemy][0] << "\nDamage: " << (*logger).enemyStats[enemy][1] << "\nShield: " << (*logger).enemyStats[enemy][2] << "\nTo: " << dynamic_cast<Enemy&>(*enemy);
}