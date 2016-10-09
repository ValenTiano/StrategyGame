#include "Game.h"

Game::Game()
{
    map = Map(5, 5);
    _type = GameType::EASY;
}


Game::~Game()
{
}

void Game::Run()
{
    map.printMap();
}