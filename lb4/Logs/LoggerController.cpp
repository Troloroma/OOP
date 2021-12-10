#include "LoggerController.h"


LoggerController::LoggerController(int mode, Entity* player, std::vector <Grid*> enemies){
	this->option = mode;
	logger = new Logger(player, enemies);
	if (mode == CONSOLE || mode == BOTH) 
		consoleLog = new ConsoleLogger(logger);
	if (mode == FILE || mode == BOTH)
		fileLog = new FileLogger(logger);
}


void LoggerController::writePlayer() {
	if (option == CONSOLE || option == BOTH) 
		consoleLog->writePlayer();
	if (option == FILE || option == BOTH) 
		fileLog->writePlayer();
}


void LoggerController::writeEnemy(Entity* enemy) {
	if (option == CONSOLE || option == BOTH) 
		consoleLog->writeEnemy(enemy);
	if (option == FILE || option == BOTH) 
		fileLog->writeEnemy(enemy);
}


LoggerController::~LoggerController() {
	delete logger;
	if (option == CONSOLE || option == BOTH) 
		delete consoleLog;
	if (option == FILE || option == BOTH)
		delete fileLog;
}