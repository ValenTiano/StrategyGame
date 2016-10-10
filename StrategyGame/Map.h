#pragma once
#include "Tile.h"
#include <vector>
#include <SFML\Graphics.hpp>

class Map
{
public:
    Map(unsigned int cols, unsigned int rows); //конструктор
    ~Map();
    void PaintTile(int x, int y, TileType type); // замальовує клітинку за координатами, і типом клітинки.
    Tile getTile(int x, int y); //мало б брати клітинку, за координатами і повертати її
    std::vector<std::vector<Tile *>> _tile; // 2х вимірний вертор (спец масив) з посилань на клітки
    void PaintNeigbers(int x, int y); //Замальовуєм сусідів
private:
	unsigned int _cols;	//число колонок
    unsigned int _rows; //число рядків
Map();
};

