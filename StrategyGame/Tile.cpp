#include "Tile.h"
#include <iostream>

using namespace sf;

Tile::Tile()
{
}

Tile::Tile(char symbol, int xCords, int yCords)
{
    _type = symbol;
    _xCords = xCords;
    _yCords = yCords;
}

Tile::~Tile()
{
}

CircleShape Tile::getSprite()
{
    CircleShape hexagon(60, 6);
    hexagon.setRotation(90.f);
    switch (_type) {
    case '0':
        hexagon.setFillColor(Color::White);
        break;
    case 'B':
        hexagon.setFillColor(Color::Cyan);
        break;
    case 'W':
        hexagon.setFillColor(Color::Red);
        break;
    default:
        break;
    }
    float x = 150 + _xCords*92.0f;
    float y = _yCords*105.0f;
    if ((_xCords % 2) == 1) {
        y += 52.0f;
    }
    hexagon.setPosition(Vector2f(x, y));
    return hexagon;
}
