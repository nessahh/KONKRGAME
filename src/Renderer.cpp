#include "Renderer.hpp"
#include <cmath>
#include <iostream> // Ajoutez cette ligne pour utiliser std::cout


#include <iostream>
#include <cmath>
#include "Renderer.hpp"

Renderer::Renderer(SDL_Renderer* renderer) : renderer(renderer) {}

void Renderer::setColor(TileType type) {
    switch (type) {
        case TileType::Water:
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Bleu
            std::cout << "🟦 Couleur : Bleu (Eau)\n";
            break;
        case TileType::Plain:
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Vert
            std::cout << "🟩 Couleur : Vert (Plaine)\n";
            break;
        case TileType::City:
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Jaune
            std::cout << "🏠 Couleur : Jaune (Ville)\n";
            break;
        case TileType::Tower:
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Rouge
            std::cout << "🏰 Couleur : Rouge (Tour)\n";
            break;
        default:
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Blanc par défaut
            std::cout << "⚪ Couleur : Blanc (Défaut)\n";
            break;
    }
}


void Renderer::drawMap(const Map& map, int hexSize) {
    const auto& tiles = map.getTiles();
    
    int mapWidth = tiles[0].size() * hexSize;
    int mapHeight = tiles.size() * hexSize;
    
    // 🟢 Centre la carte au milieu de la fenêtre
    int startX = (800 - mapWidth) / 2;  
    int startY = (600 - mapHeight) / 2;

    for (size_t y = 0; y < tiles.size(); ++y) {
        for (size_t x = 0; x < tiles[y].size(); ++x) {
            setColor(tiles[y][x].type);

            int centerX = startX + x * (hexSize + 1);
            int centerY = startY + y * (hexSize + 1);

            SDL_Rect rect = {centerX, centerY, hexSize, hexSize};
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}




void Renderer::drawHex(int centerX, int centerY, int hexSize) {
    const int numSides = 6;
    const double angleOffset = M_PI / 6; // Décalage de 30 degrés pour orienter les hexagones

    SDL_Point points[numSides + 1];
    for (int i = 0; i < numSides; ++i) {
        double angle = angleOffset + 2 * M_PI * i / numSides;
        points[i].x = centerX + hexSize * cos(angle);
        points[i].y = centerY + hexSize * sin(angle);
    }
    points[numSides] = points[0]; // Fermer l'hexagone

    SDL_RenderDrawLines(renderer, points, numSides + 1);
}


