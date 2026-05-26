#include "cheat.h"
#include <vector>
#include <iostream>
using namespace std;

Cheat::Cheat(Game& game) : game(game) { visitedCount = 0; }

Vector2 Cheat::getNextMove()
{   
    winningpath.clear();

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            visited[row][col] = false;
        }
    }
    visitedCount = 0;
    for(auto tile: game.traveledTiles)
    {
        visited[(int)tile.x/100][(int)tile.y/100] = true;
    }

    int currX = game.knight.x;
    int currY = game.knight.y;

    if(algorithim(currX, currY))
    {
        return winningpath.at(1);
    }
    return {-1, -1};
}

/*
The algorithim works by initially pushing the current tile coords into the winningpath vector
Then it checks if goal is reached then it will return true;

The current tile is gonna be marked as true as it's visited.
Then it will enter the for loop where we set next tiles to variables.
Then we check if the next tiles, the tiles we already visited in game and the tiles we visited in our 
algorithim test haven't been visited. If one of them has been visited then we check the next of 8 different
moves we can perform from a tile until we find a tile we haven't visited.
If no valid tiles then we will pop the current tile and then go back to the prev tile
and loop through the different possibilites again. 
This will happen until we find the final solution if there is any and will return true
if there is a valid path and false if not. 
*/
bool Cheat::algorithim(int currX, int currY)
{ 
    int row = currX / 100;
    int col = currY / 100;

    winningpath.push_back({(float)currX, (float)currY});

    visited[row][col] = true;
    visitedCount++; 

    if(visitedCount == 25 - game.traveledTiles.size())
        return true;

    int dx[8] = { -2, 2, -2, 2, -1, -1, 1, 1 };
    int dy[8] = { -1, -1, 1, 1, -2, 2, -2, 2 };

    for(int i = 0; i < 8; i++)
    {
        int nextX = currX + dx[i] * game.knight.cellSize;
        int nextY = currY + dy[i] * game.knight.cellSize;

        if(game.isValidMove(nextX, nextY))
        {
            int nextRow = nextX / 100;
            int nextCol = nextY / 100;

            if(!visited[nextRow][nextCol])
            {
                if(algorithim(nextX, nextY))
                    return true;
            }
        }
    }

    winningpath.pop_back();
    visited[row][col] = false;
    visitedCount--; 

    return false;
}