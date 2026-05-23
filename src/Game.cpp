#include "Game.h"
#include "colors.h"


void Game::Draw()
{
    grid.Draw();
    knight.Draw();
}

void Game::Print()
{
    grid.Print();
}

void Game::handleInput()
{
    if(IsKeyDown(KEY_LEFT) && IsKeyPressed(KEY_UP))
    {
        int newY = knight.y - knight.cellSize;
        int newX = knight.x - (knight.cellSize * 2);

        if(isValidMove(newX, newY))
        {
            knight.x = newX;
            knight.y = newY;
        }
    }

    if(IsKeyDown(KEY_RIGHT) && IsKeyPressed(KEY_UP))
    {
        int newY = knight.y - knight.cellSize;
        int newX = knight.x + (knight.cellSize * 2);

        if(isValidMove(newX, newY))
        {
            knight.x = newX;
            knight.y = newY;
        }
    }

    if(IsKeyDown(KEY_LEFT) && IsKeyPressed(KEY_DOWN))
    {
        int newY = knight.y + knight.cellSize;
        int newX = knight.x - (knight.cellSize * 2);

        if(isValidMove(newX, newY))
        {
            knight.x = newX;
            knight.y = newY;
        }
    }

    if(IsKeyDown(KEY_RIGHT) && IsKeyPressed(KEY_DOWN))
    {
        int newY = knight.y + knight.cellSize;
        int newX = knight.x + (knight.cellSize * 2);

        if(isValidMove(newX, newY))
        {
            knight.x = newX;
            knight.y = newY;
        }
    }

    if(IsKeyDown(KEY_UP) && IsKeyPressed(KEY_LEFT))
    {
        int newY = knight.y - (knight.cellSize * 2);
        int newX = knight.x - knight.cellSize;

        if(isValidMove(newX, newY))
        {
            knight.x = newX;
            knight.y = newY;
        }
    }

    if(IsKeyDown(KEY_DOWN) && IsKeyPressed(KEY_LEFT))
    {
        int newY = knight.y + (knight.cellSize * 2);
        int newX = knight.x - knight.cellSize;

        if(isValidMove(newX, newY))
        {
            knight.x = newX;
            knight.y = newY;
        }
    }

    if(IsKeyDown(KEY_UP) && IsKeyPressed(KEY_RIGHT))
    {
        int newY = knight.y - (knight.cellSize * 2);
        int newX = knight.x + knight.cellSize;

        if(isValidMove(newX, newY))
        {
            knight.x = newX;
            knight.y = newY;
        }
    }

    if(IsKeyDown(KEY_DOWN) && IsKeyPressed(KEY_RIGHT))
    {
        int newY = knight.y + (knight.cellSize * 2);
        int newX = knight.x + knight.cellSize;

        if(isValidMove(newX, newY))
        {
            knight.x = newX;
            knight.y = newY;
        }
    }
}

bool Game::isValidMove(int newX, int newY)
{
    if(newX < 0 || newX >= 500 ||
       newY < 0 || newY >= 500)
    {
        return false;
    }

    return true;
}