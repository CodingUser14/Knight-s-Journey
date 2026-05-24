#pragma once
#include "colors.h"

class Knight
{
public:
    Knight();
    void Draw();
    void ResetKnightPosition();
    int x;
    int y;
    int cell;
    int cellSize;
    Color color;
};