#include "knight.h"
#include <cstdlib>
#include <iostream>

Knight::Knight()
{
    cell = (rand() % 13);
    switch(cell)
    {
        case 0:
            x = 0;
            y = 0;
            break;
        case 1:
            x = 200;
            y = 0;
            break;
        case 2:
            x = 400;
            y = 0;
            break;
        case 3:
            x = 100;
            y = 100;
            break;
        case 4:
            x = 300;
            y = 100;
            break;
        case 5:
            x = 0;
            y = 200;
            break;
        case 6:
            x = 200;
            y = 200;
            break;
        case 7:
            x = 400;
            y = 200;
            break;
        case 8:
            x = 100;
            y = 300;
            break;
        case 9:
            x = 300;
            y = 300;
            break;
        case 10:
            x = 0;
            y = 400;
            break;
        case 11:
            x = 200;
            y = 400;
            break;
        case 12:
            x = 400;
            y = 400;
            break;
    }
    printf("%d", cell);
    cellSize = 100;
    color = getCellColors()[2];
}

void Knight::Draw()
{
    DrawRectangle(x, y, cellSize, cellSize, color);
}

