#include <raylib.h>
#include "Game.h"
#include <ctime>
#include <cstdlib>
using namespace std;
/*


*/


int main() 
{
    srand((unsigned)time(NULL));
    Game game = Game();
    InitWindow(100 * 5, 100 * 5, "A knight's Journey"); 
    SetTargetFPS(60);
    game.Print(); 



    while(WindowShouldClose() == false)
    {

        game.handleInput();
        Color green = {173, 204, 96, 255};
        BeginDrawing();
        ClearBackground(green);

        game.Draw();  
        EndDrawing();
    }
    CloseWindow();
    return 0;
}