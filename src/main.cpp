#include <raylib.h>
#include "Game.h"
#include <ctime>
#include <cstdlib>
using namespace std;


int main() 
{
    srand((unsigned)time(NULL));
    Game game = Game();
    InitWindow(100 * 5, 100 * 5, "A knight's Journey"); 
    SetTargetFPS(60);
    game.Print();  
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);



    while(WindowShouldClose() == false)
    {

        game.handleInput();
        Color green = {173, 204, 96, 255};
        BeginDrawing();
        ClearBackground(green);

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