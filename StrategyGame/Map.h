#pragma once
#include "Tile.h"
#include <vector>
#include <SFML\Graphics.hpp>

class Map
{
public:
    Map(unsigned int cols, unsigned int rows);
    ~Map();
    void PaintTile(int x, int y, TileType type);
    Tile getTile(int x, int y);
    std::vector<std::vector<Tile *>> _tile;
    void PaintNeigbers(int x, int y);:
private:
unsigned int _cols;
    unsigned int _rows;
Map();
};

