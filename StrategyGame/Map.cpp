#include "Map.h"
#include <iostream>

Map::Map() {
    _cols = 5;
    _rows = 5;
    _tile = new Tile*[_rows];
    for (unsigned int i = 0; i < _rows; ++i) {
        _tile[i] = new Tile[_cols];
        for (unsigned int j = 0; j < _cols; ++j) {
            _tile[i][j] = Tile('O');
        }
    }

}

Map::Map(unsigned int cols, unsigned int rows)
{
    _cols = cols;
    _rows = rows;
    _tile = new Tile*[_rows];
    for (unsigned int i = 0; i < _rows; ++i) {
        _tile[i] = new Tile[_cols];
        for (unsigned int j = 0; j < _cols; ++j) {
            _tile[i][j] = Tile();
        }
    }
}

Map::~Map()
{
    for (unsigned int i = 0; i < _rows; i++) {
        delete[] _tile[i];
    }
    delete[] _tile;
}

void Map::printMap() {
    for (unsigned int i = 0; i < _cols; i++) {
        for (unsigned int j = 0; j < _rows; j++) {
            _tile[j][i].Print();
        }
        std::cout << std::endl;
    }
}
