#include "../include/game.h"

int main(){
    int x, y;
    cin >> x;
    cin >> y;
    Game game (x, y);
    game.runGame(x, y);
    return 0;
}