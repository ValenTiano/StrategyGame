#pragma once
class Tile
{
public:
    Tile();
    Tile(char symbol);
    ~Tile();
    void Print();
private:
    char _type;
};

