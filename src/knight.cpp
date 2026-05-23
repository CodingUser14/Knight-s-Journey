#include "knight.h"
#include <cstdlib>

Knight::Knight()
{
    x = (rand() % 5) * 100;
    y = (rand() % 5) * 100;
    cellSize = 100;
    color = getCellColors()[2];
}

void Knight::Draw()
{
    DrawRectangle(x, y, cellSize, cellSize, color);
}

