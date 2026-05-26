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
    int visitedCount;


private:
    Game& game;
    vector<Vector2> winningpath;

    bool visited[5][5];
    Color color;
    int cellSize;

};