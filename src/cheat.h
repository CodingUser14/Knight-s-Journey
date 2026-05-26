#pragma once
#include <vector>
#include <raylib.h>
#include "Game.h"
using namespace std;



class Cheat 
{
public:
    Cheat(Game& game);

    bool algorithim(int x, int y);
    Vector2 getNextMove();

private:
    Game& game;
    vector<Vector2> winningpath;

    bool visited[5][5];

    int visitedCount;
    Color color;
    int cellSize;

};