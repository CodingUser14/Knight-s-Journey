#pragma once
#include "colors.h"

class Knight
{
public:
    Knight();
    void Draw();
    int x;
    int y;
    int cell;
    int cellSize;
    Color color;
};