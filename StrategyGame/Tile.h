#pragma once
#include <SFML\Graphics.hpp>

enum TileType { EMPTY, RED_BASE, BLUE_BASE, RED, BLUE, RED_FORT, BLUE_FORT };

class Tile
{
public:
    Tile(TileType symbol, int xCords, int yCords);
    ~Tile();
    sf::CircleShape getSprite();
    void setType(TileType type);
    void PaintNeighbors();
    TileType getType();
private:
    TileType _type;
    int _xCords;
    int _yCords;
    Tile();
};

