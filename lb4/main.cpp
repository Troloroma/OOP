#include "Game/Game.cpp"

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Game<Rules<3>> newGame;
	newGame.game();
}