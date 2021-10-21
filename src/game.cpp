#include "../include/game.h"

Game::Game(int x, int y){}

void Game::runGame(int x, int y){
    this->field = new Field(x, y);
}

Game::~Game(){
    delete field;
}