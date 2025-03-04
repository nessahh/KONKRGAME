#include "Map.hpp"
#include <fstream>   // Pour std::ifstream
#include <iostream>  // Pour std::cout, std::cerr, std::endl
#include <string>    // Pour std::string
#include <vector>    // Pour std::vector



Map::Map(const std::string& filename) {
    loadFromFile(filename); // Charge la carte depuis le fichier
}

void Map::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "❌ Erreur : impossible de charger la carte " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<Tile> row;
        for (char c : line) {
            switch (c) {
                case 'W': row.push_back({TileType::Water}); break;
                case '.': row.push_back({TileType::Plain}); break;
                case 'V': row.push_back({TileType::City}); break;
                case 'T': row.push_back({TileType::Tower}); break;
                default: row.push_back({TileType::Plain}); break;
            }
        }
        tiles.push_back(row);
    }

    
    // 🟢 Vérification : Afficher la carte ASCII dans le terminal
    std::cout << "✅ Carte chargée depuis " << filename << " :\n";
    for (const auto& row : tiles) {
        for (const auto& tile : row) {
            char symbol = (tile.type == TileType::Water) ? 'W' :
                          (tile.type == TileType::Plain) ? '.' :
                          (tile.type == TileType::City) ? 'V' : 'T';
            std::cout << symbol;
        }
        std::cout << std::endl;
    }
}

// Méthode pour obtenir les tuiles
const std::vector<std::vector<Tile>>& Map::getTiles() const {
    return tiles;
}