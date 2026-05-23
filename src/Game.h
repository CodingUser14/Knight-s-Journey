#include "Grid.h"
#include "knight.h"

class Game
{
public:
    void Draw();
    void handleInput();
    void Print();
    bool isValidMove(int newX, int newY);
    Grid grid;
    Knight knight;
    bool running = true;
};