#pragma once


class Tile
{
public:
    Tile();
    Tile(float x, float y);
    ~Tile();
    void Print();
    void Init();

private:
    int _xPos;
    int _yPos;
    float _xCords;
    float _yCords;
    int _width;
    int _height;
};

