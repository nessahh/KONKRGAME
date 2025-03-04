#include "../include/Game.hpp"
#include <iostream>

int main() {
    Game game;
    if (game.init()) {
        game.run();
    }
    game.clean(); // N'oubliez pas de nettoyer les ressources SDL
    return 0;
}