#include "Tile.h"
#include <iostream>

using namespace sf;

Tile::Tile()
{
}

Tile::Tile(TileType symbol, int xCords, int yCords)
{
    _type = symbol;
    _xCords = xCords;
    _yCords = yCords;
}

Tile::~Tile()
{

}

TileType Tile::getType() {
    return _type;
}

void Tile::setType(TileType type) {
    _type = type;
}



CircleShape Tile::getSprite()
{
    CircleShape hexagon(60, 6);
    hexagon.setRotation(90.f);
    Texture t;
    switch (_type) {
    case BLUE:
        hexagon.setFillColor(Color::Blue);
        break;
    case RED:
        hexagon.setFillColor(Color::Red);
        break;
    case BLUE_FORT:
        hexagon.setFillColor(Color::Blue);
        t.loadFromFile("images/fort.jpg");
        hexagon.setTexture(&t);
        break;
    case RED_FORT:
        hexagon.setFillColor(Color::Red);
        t.loadFromFile("images/fort.jpg");
        hexagon.setTexture(&t);
        break;
    case BLUE_BASE:
        hexagon.setFillColor(Color::Blue);
        t.loadFromFile("images/castle.jpg");
        hexagon.setTexture(&t);
        break;
    case RED_BASE:
        hexagon.setFillColor(Color::Red);
        t.loadFromFile("images/castle.jpg");
        hexagon.setTexture(&t);
        break;

    default:
        hexagon.setFillColor(Color::White);
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
