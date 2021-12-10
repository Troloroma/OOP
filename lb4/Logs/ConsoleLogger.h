#pragma once
#include "Logger.h"

class ConsoleLogger : public Logger {
public:
	Logger* logger;
	ConsoleLogger(Logger* logger) { this->logger = logger; };
	void writePlayer();
	void writeEnemy(Entity* enemy);
};