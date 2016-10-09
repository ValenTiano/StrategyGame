#include "Tile.h"
#include <iostream>

Tile::Tile()
{
    _type = 'O';
}

Tile::Tile(char symbol)
{
    _type = symbol;
}

Tile::~Tile()
{
}

void Tile::Print() {
    std::cout << _type;
}
