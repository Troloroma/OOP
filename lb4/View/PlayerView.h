#pragma once
#include "../Game/Entity/Player.h"


class PlayerView {
private:
	Player& mainPlayer;
public:
	PlayerView(Player& obj);
	void printStats();
};