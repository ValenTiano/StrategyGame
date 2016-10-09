#pragma once
#include "Tile.h"
#include <vector>
#include <SFML\Graphics.hpp>

class Map
{
public:
    Map(unsigned int cols, unsigned int rows);
    ~Map();
    Tile getTile(int x, int y);
private:

    unsigned int _cols;
    unsigned int _rows;
    std::vector<std::vector<Tile>> _tile;
    Map();
};

