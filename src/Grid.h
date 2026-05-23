#pragma once
#include <vector>
#include <raylib.h>
using namespace std;

class Grid
{
public:
    Grid();
    void Initialization();
    void Draw();
    void Print();
    int grid[5][5];

    int numRows;
    int numCols;
    int cellSize;
    vector<Color> colors;
};