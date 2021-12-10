#include "Objects/Field.h"
#include "Entity/Player.h"

template<int EnemiesDead>
class Rules{
public:
    Rules() = default;
    bool gameProcess(Field& field, int amount);
    bool EnemiesDeadCounter(int amount);
};

template<int EnemiesDead>
bool Rules<EnemiesDead>::EnemiesDeadCounter(int amount){
    return EnemiesDead <= amount;
}

template<int EnemiesDead>
bool Rules<EnemiesDead>::gameProcess(Field& field, int amount) {
	if ((field.getExit() == field.getPlayer()) || ((dynamic_cast<Player&>(*field.getPlayer()->getEntity())).getHp() <= 0)) {
		if ((dynamic_cast<Player&>(*field.getPlayer()->getEntity())).getHp() <= 0) {
			std::cout << "Player died.\n\n";
		}
		else {
            if(EnemiesDeadCounter(amount)){
                std::cout << "You won.\n";
            }
            else{ std::cout << "You haven't killed enough enemies.\n"; return 1;}
		}
		return 0;
	}
	else {
		return 1;
	}
}