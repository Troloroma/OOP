//#include "Objects/Field.h"
#include"Game.h"
		
template<class VictoryChecker>
void Game<VictoryChecker>::game(){
	VictoryChecker rules;
	char dir;
	int height, width, iterator, mode;
	std::cout << "Enter width = ";
	std::cin >> height;
	std::cout << "Enter height = ";
	std::cin >> width;
	std::cout << '\n';
	std::cout << "Where to output logs? 0 - console, 1 - file, 2 - both, other number - nowhere\n";
	std::cin >> mode;
	std::cout << '\n';
	Field modelField(width, height);
	FieldView field(modelField);
	field.print();
	iterator = 0;
	LoggerController logger (mode, modelField.getPlayer()->getEntity(), modelField.enemies);
	while (rules.gameProcess(modelField, modelField.getStartEnemiesAmount() - modelField.enemies.size())) {
		std::cout << "Enter direction, W - up, S - down, D - right, A - left:";
		std::cin >> dir;
		modelField.moveEntity(*modelField.getPlayer(), dir);
		for (int i = 0; i < modelField.enemies.size(); i++) {
			if (typeid(*((*modelField.enemies[i]).getEntity())).name() == typeid(Knight).name()) {
				(dynamic_cast<Knight&>(*modelField.enemies[i]->getEntity())).changeDirection(iterator);
			}
			if (typeid(*((*modelField.enemies[i]).getEntity())).name() == typeid(Horseman).name()) {
				(dynamic_cast<Horseman&>(*modelField.enemies[i]->getEntity())).changeDirection(iterator);
			}
			if (typeid(*((*modelField.enemies[i]).getEntity())).name() == typeid(Wolf).name()) {
				(dynamic_cast<Wolf&>(*modelField.enemies[i]->getEntity())).changeDirection(iterator);
			}
			modelField.moveEntity(*modelField.enemies[i], (dynamic_cast<Enemy&>(*modelField.enemies[i]->getEntity())).getDirection(), i);
		}
		if (dynamic_cast<Player&>(*modelField.getPlayer()->getEntity()).getHp() != (*logger.logger).playerStats[0] || dynamic_cast<Player&>(*modelField.getPlayer()->getEntity()).getDamage() != (*logger.logger).playerStats[1] || dynamic_cast<Player&>(*modelField.getPlayer()->getEntity()).getShield() != (*logger.logger).playerStats[2]) {
			logger.writePlayer();
			(*logger.logger).clonePlayer();
		}
		for (int i = 0; i < modelField.enemies.size(); i++) {
			if (dynamic_cast<Enemy&>(*modelField.enemies[i]->getEntity()).getHp() != (*logger.logger).enemyStats[modelField.enemies[i]->getEntity()][0]) {
				logger.writeEnemy(modelField.enemies[i]->getEntity());
				(*logger.logger).cloneEnemy(modelField.enemies[i]->getEntity());
			}
		}
		iterator++;
		field.print();
	}
}