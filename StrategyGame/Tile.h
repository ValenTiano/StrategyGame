#pragma once
#include <SFML\Graphics.hpp>

class Tile
{
public:
    Tile(char symbol, int xCords, int yCords);
    ~Tile();
    sf::CircleShape getSprite();
private:
    char _type;
    int _xCords;
    int _yCords;
    Tile();
};

