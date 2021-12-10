#include "PlayerView.h"

PlayerView::PlayerView(Player& obj) : mainPlayer(obj) {}
void PlayerView::printStats() {
	std::cout << "\nPlayer stats: Hp points: " << mainPlayer.getHp() << ", shield: " << mainPlayer.getShield() << ", damage: " << mainPlayer.getDamage() << "\n";
}