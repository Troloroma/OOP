#pragma once
#include "ConsoleLogger.h"
#include "FileLogger.h"

class LoggerController {
public:
	int option;
	LoggerController() = default;
	LoggerController(int option, Entity* player, std::vector <Grid*> enemies);
	Logger* logger;
	ConsoleLogger* consoleLog;
	FileLogger* fileLog;
	void writePlayer();
	void writeEnemy(Entity* enemy);
	~LoggerController();

	enum Mode {CONSOLE, FILE, BOTH};
};