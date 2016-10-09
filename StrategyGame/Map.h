#pragma once
#include "Tile.h"

class Map
{
public:
    Map();
    Map(unsigned int cols, unsigned int rows);
    ~Map();
    void printMap();
private:
    unsigned int _cols;
    unsigned int _rows;
    Tile ** _tile;

};

