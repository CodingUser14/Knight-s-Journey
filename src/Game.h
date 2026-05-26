#pragma once
#include "Grid.h"
#include "knight.h"
#include <vector>
#include <raylib.h>


class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void handleInput();
    void Print();
    bool isValidMove(int newX, int newY);
    bool gameOver(int x, int y);
    std::vector<Vector2> traveledTiles;

    //cheat button 
    Grid grid;
    Knight knight;
    void reset();
    int score;
    int tile;
};