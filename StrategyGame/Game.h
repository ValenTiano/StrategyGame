#pragma once
#include "Map.h"

enum GameType {EASY, MEDIUM, HARD};

class Game
{
public:
    Game();
    ~Game();

    void Run();
private:
    GameType _type;
    Map map;
};

