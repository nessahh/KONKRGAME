#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include "Map.hpp"

class Renderer {
public:
    explicit Renderer(SDL_Renderer* renderer);
    ~Renderer() = default;

    void drawMap(const Map& map, int hexSize);
    
private:
    SDL_Renderer* renderer;
    
    void setColor(TileType type);
    void drawHex(int x, int y, int hexSize); // Ajout d'une méthode pour dessiner un hexagone
};

#endif
