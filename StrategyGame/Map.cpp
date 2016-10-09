#include "Map.h"
#include <iostream>

Map::Map() {}

Map::Map(unsigned int cols, unsigned int rows)
{
    _cols = cols;
    _rows = rows;
    unsigned int lRows = _rows;
    unsigned int lCols = _cols;

    std::vector<Tile*> tile_vector;
    for (unsigned int i = 0; i < _rows; i++) {
        tile_vector.clear();
        for (unsigned int j = 0; j < _cols; j++) {
            tile_vector.push_back(new Tile(EMPTY, i, j));
        }
        _tile.push_back(tile_vector);
    }
}

Map::~Map()
{
}

Tile Map::getTile(int x, int y) {
    return *_tile[x][y];
}

void Map::PaintTile(int x, int y, TileType type) {
    
    this->_tile[x-1][y-1]->setType(type);
}

void Map::PaintNeigbers(int x, int y) {

}
