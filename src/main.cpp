#include <raylib.h>
#include "Game.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


int main() 
{
    srand((unsigned)time(NULL));
    Game game = Game();
    InitWindow(100 * 5 + 150, 100 * 5, "A knight's Journey"); 
    SetTargetFPS(60);
    game.Print();  
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    printf("%d", game.knight.cell);


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

        if(game.gameOver(game.knight.x, game.knight.y))
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE); // text            
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}