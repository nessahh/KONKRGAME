#ifndef GAME_HPP
#define GAME_HPP
#undef main


#include <SDL2/SDL.h>

class Game {
public:
    Game();
    ~Game() = default;

    bool init();
    void run();
    void handleEvents();
    void clean();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;

    int cameraX = 0, cameraY = 0;  // 🟢 Ajout des variables de déplacement
};

#endif
