#include "FileLogger.h"

FileLogger::FileLogger(Logger* logger) { 
	this->logger = logger;
	file.open("logs.txt");
}

void FileLogger::writePlayer() {
	file << "\n[HERO CHANGE]\n";
	file << "From:\nHp: " << (*logger).playerStats[0] << "\nDamage: " << (*logger).playerStats[1] << "\nShield: " << (*logger).playerStats[2] << "\nTo: " << dynamic_cast<Player&>(*(*logger).player_);
}

void FileLogger::writeEnemy(Entity* enemy) {
	file << "\n[ENEMY_CHANGE]\n";
	file << "From:\nHp: " << (*logger).enemyStats[enemy][0] << "\nDamage: " << (*logger).enemyStats[enemy][1] << "\nShield: " << (*logger).enemyStats[enemy][2] << "\nTo: " << dynamic_cast<Enemy&>(*enemy);
}


FileLogger::~FileLogger() {
	file.close();
}