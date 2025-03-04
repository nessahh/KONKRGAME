#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <string>

enum class TileType { Water, Plain, City, Tower };

struct Tile {
    TileType type;
};

class Map {
public:
    explicit Map(const std::string& filename);
    ~Map() = default;

    const std::vector<std::vector<Tile>>& getTiles() const;
    
    // Ajout de méthodes pour récupérer la taille de la carte
    int getWidth() const { return tiles.empty() ? 0 : tiles[0].size(); }
    int getHeight() const { return tiles.size(); }

private:
    std::vector<std::vector<Tile>> tiles;
    void loadFromFile(const std::string& filename);
};

#endif