#include <raylib.h>
#include "Game.h"
using namespace std;
/*
Title: Stand on the Right Color
Author: Brian Kim
Date: May 04, 2026
Description: The game will display a color and the board of 36 tiles will blink for 1 sec 
and the player has to stand on the matching tile. 

Objectives for the program:
Practice c++
Pratice adt
Practice Game Development
*/


int main() 
{
    Game game = Game();
    InitWindow(30 * 36 + 1, 30 * 36 + 1, "ColorRush"); 
    SetTargetFPS(60);
    game.Print(); 

    while(WindowShouldClose() == false)
    {
        Color green = {173, 204, 96, 255};
        BeginDrawing();
        ClearBackground(green);

        game.Draw();  
        EndDrawing();
    }
    CloseWindow();
    return 0;
}