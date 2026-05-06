#include "game.h"

Game::Game()
{
    grid = Grid();
}

void Game::Draw()
{
    grid.Draw();
}

void Game::Print()
{
    grid.Print();
}