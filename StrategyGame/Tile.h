#pragma once
#include <SFML\Graphics.hpp>

enum TileType { EMPTY, RED_BASE, BLUE_BASE, RED, BLUE, RED_FORT, BLUE_FORT }; //типи клітинок

class Tile
{
public:
    Tile(TileType symbol, int xCords, int yCords); //конструктор
    ~Tile();
    sf::CircleShape getSprite(); //повертає форму для малюваня
    void setType(TileType type); //призначає тип тайлу
    TileType getType(); //повертає тип тайлу
private:
    TileType _type;
    int _xCords;
    int _yCords;
    Tile();
};

