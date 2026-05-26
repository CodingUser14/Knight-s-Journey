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

        DrawTextEx(font, "Press C for cheats", {320, 600}, 38, 2, WHITE);

        if(game.gameOver(game.knight.x, game.knight.y))
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE); // text
        }

        if(IsKeyPressed(KEY_C))
        {
            showcheat = !showcheat;
        }
        if(showcheat)
        {
            if(cheat.getNextMove().x == -1 && cheat.getNextMove().y == -1)
            {
                DrawTextEx(font, "You can't Win. Press R", {320, 650}, 38, 2, WHITE);
            }
            else
            {
                DrawCircle(cheat.getNextMove().x + 50, cheat.getNextMove().y + 50, 100/2, YELLOW);
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