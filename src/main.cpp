#include <raylib.h>
#include "Game.h"
#include "cheat.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


int main() 
{
    srand((unsigned)time(NULL));
    Game game = Game();
    Cheat cheat = Cheat(game);
    InitWindow(100 * 5 + 150, 100 * 5, "A knight's Journey"); 
    SetTargetFPS(60);
    game.Print();  
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    printf("%d", game.knight.cell);
    int showcheat = false;
    int prevMove = game.knight.x;
    Vector2 hintMove = cheat.getNextMove();

    while(WindowShouldClose() == false)
    {
        game.handleInput();
        Color green = {173, 204, 96, 255};
        BeginDrawing();
        ClearBackground(green);

        DrawTextEx(font, "Score: ", {520, 30}, 38, 2, WHITE);      
        
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {500 + (100 - textSize.x)/2, 70}, 38, 2, WHITE);
        game.Draw(); 

        DrawTextEx(font, "Press R", {510, 170}, 20, 2, BLUE);
        DrawTextEx(font, "to Restart", {510, 185}, 20, 2, BLUE);

        DrawTextEx(font, "Press C", {510, 130}, 20, 2, BLUE);
        DrawTextEx(font, "for cheats", {510, 145}, 20, 2, BLUE);

        if(game.gameOver(game.knight.x, game.knight.y))
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE); // text
        }
        else
        {
            hintMove = cheat.getNextMove();
        }
        
        if(IsKeyPressed(KEY_C))
        {
            showcheat = !showcheat;
        }
        if(showcheat && !game.gameOver(game.knight.x, game.knight.y))
        {
            if(prevMove != game.knight.x) //cause curr x can never be the same as prev
            {
                prevMove = game.knight.x;
                cout << hintMove.x << " " << hintMove.y;
            }
            if(hintMove.x == -1 && hintMove.y == -1)
            {
                DrawTextEx(font, "You", {510, 360}, 38, 2, BLACK);
                DrawTextEx(font, "can't", {510, 385}, 38, 2, BLACK);
                DrawTextEx(font, "win", {510, 410}, 38, 2, BLACK);
                DrawTextEx(font, "Press R", {510, 435}, 38, 2, BLACK);
            }
            else
            {
                DrawCircle(hintMove.x + 50, hintMove.y + 50, 100/2, YELLOW);
            }
        }
        if(IsKeyPressed(KEY_R))
        {
            game.reset();
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}