#include "Game.h"
#include "colors.h"
#include <raylib.h>
#include <vector>
#include <cstdlib>

Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

Game::Game() : score{0}, tile{0} { grid = Grid(); }

Game::~Game() {}

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

    if(gameOver(knight.x, knight.y) && GetKeyPressed() != 0)
    {
        if(tile == 24){
            score++;
        }
        reset();
    }

    if(IsKeyDown(KEY_LEFT) && IsKeyPressed(KEY_UP))
    {
        int newY = knight.y - knight.cellSize;
        int newX = knight.x - (knight.cellSize * 2);

        if(isValidMove(newX, newY))
        {
            grid.grid[knight.y/100][knight.x/100] = 5;
            traveledTiles.push_back({(float)knight.x, (float)knight.y});
            knight.x = newX;
            knight.y = newY;
            tile++;
        }
    }
    else if(IsKeyDown(KEY_RIGHT) && IsKeyPressed(KEY_UP))
    {
        int newY = knight.y - knight.cellSize;
        int newX = knight.x + (knight.cellSize * 2);

        if(isValidMove(newX, newY))
        {
            grid.grid[knight.y/100][knight.x/100] = 5;
            traveledTiles.push_back({(float)knight.x, (float)knight.y});
            knight.x = newX;
            knight.y = newY;
            tile++;
        }
    }
    else if(IsKeyDown(KEY_LEFT) && IsKeyPressed(KEY_DOWN))
    {
        int newY = knight.y + knight.cellSize;
        int newX = knight.x - (knight.cellSize * 2);

        if(isValidMove(newX, newY))
        {
            grid.grid[knight.y/100][knight.x/100] = 5;
            traveledTiles.push_back({(float)knight.x, (float)knight.y});
            knight.x = newX;
            knight.y = newY;
            tile++;
        }
    }
    else if(IsKeyDown(KEY_RIGHT) && IsKeyPressed(KEY_DOWN))
    {
        int newY = knight.y + knight.cellSize;
        int newX = knight.x + (knight.cellSize * 2);

        if(isValidMove(newX, newY))
        {
            grid.grid[knight.y/100][knight.x/100] = 5;
            traveledTiles.push_back({(float)knight.x, (float)knight.y});
            knight.x = newX;
            knight.y = newY;
            tile++;
        }
    }
    else if(IsKeyDown(KEY_UP) && IsKeyPressed(KEY_LEFT))
    {
        int newY = knight.y - (knight.cellSize * 2);
        int newX = knight.x - knight.cellSize;

        if(isValidMove(newX, newY))
        {
            grid.grid[knight.y/100][knight.x/100] = 5;
            traveledTiles.push_back({(float)knight.x, (float)knight.y});
            knight.x = newX;
            knight.y = newY;
            tile++;
        }
    }
    else if(IsKeyDown(KEY_DOWN) && IsKeyPressed(KEY_LEFT))
    {
        int newY = knight.y + (knight.cellSize * 2);
        int newX = knight.x - knight.cellSize;

        if(isValidMove(newX, newY))
        {
            grid.grid[knight.y/100][knight.x/100] = 5;
            traveledTiles.push_back({(float)knight.x, (float)knight.y});
            knight.x = newX;
            knight.y = newY;
            tile++;
        }
    }
    else if(IsKeyDown(KEY_UP) && IsKeyPressed(KEY_RIGHT))
    {
        int newY = knight.y - (knight.cellSize * 2);
        int newX = knight.x + knight.cellSize;

        if(isValidMove(newX, newY))
        {
            grid.grid[knight.y/100][knight.x/100] = 5;
            traveledTiles.push_back({(float)knight.x, (float)knight.y});
            knight.x = newX;
            knight.y = newY;
            tile++;
        }
    }
    else if(IsKeyDown(KEY_DOWN) && IsKeyPressed(KEY_RIGHT))
    {
        int newY = knight.y + (knight.cellSize * 2);
        int newX = knight.x + knight.cellSize;

        if(isValidMove(newX, newY))
        {
            grid.grid[knight.y/100][knight.x/100] = 5;
            traveledTiles.push_back({(float)knight.x, (float)knight.y});
            knight.x = newX;
            knight.y = newY;
            tile++;
        }
    }
    
}

bool Game::isValidMove(int newX, int newY)
{
    if(newX < 0 || newX > 400 || newY < 0 || newY > 400)
    {
        return false;
    }

    for(Vector2 tile: traveledTiles)
    {
        if(tile.x == newX && tile.y == newY)
        {
            return false;
        }
    }
    return true;
}

bool Game::gameOver(int newX, int newY)
{
    int check = 0;
    
    if(isValidMove(newX - (knight.cellSize * 2), newY - knight.cellSize)) check += 1;
    if(isValidMove(newX + (knight.cellSize * 2), newY - knight.cellSize)) check += 1;
    if(isValidMove(newX - (knight.cellSize * 2), newY + knight.cellSize)) check += 1;
    if(isValidMove(newX + (knight.cellSize * 2), newY + knight.cellSize)) check += 1;

    if(isValidMove(newX - knight.cellSize, newY - (knight.cellSize * 2))) check += 1;
    if(isValidMove(newX - knight.cellSize, newY + (knight.cellSize * 2))) check += 1;
    if(isValidMove(newX + knight.cellSize, newY - (knight.cellSize * 2))) check += 1;
    if(isValidMove(newX + knight.cellSize, newY + (knight.cellSize * 2))) check += 1;

    if(check > 0) return false;
    return true;
}

void Game::reset()
{
    traveledTiles.clear();
    grid.Initialization();
    knight.ResetKnightPosition();
    tile = 0;
}