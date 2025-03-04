#include "../include/Game.hpp"
#include "Renderer.hpp"
#include "Map.hpp"
#include <iostream>
Game::Game() : window(nullptr), renderer(nullptr), running(false) {}

bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return false;

    window = SDL_CreateWindow("Konkr Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    running = true;
    return true;
}

void Game::run() {
    Renderer mapRenderer(renderer);
  Map map("../assets/map.txt");


    while (running) {
        handleEvents();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        std::cout << "🟢 Appel à drawMap()\n";
        mapRenderer.drawMap(map, 25);

        

        SDL_RenderPresent(renderer);
        SDL_Delay(1000); // Pause pour voir l'affichage
    }
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int mouseX = event.button.x;
                    int mouseY = event.button.y;
                    std::cout << "Clic à (" << mouseX << ", " << mouseY << ")\n";
                    // Convertir les coordonnées de la souris en coordonnées de la grille hexagonale
                }
                break;
        }
    }
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
