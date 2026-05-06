#include "Grid.h"
#include "colors.h"
#include <iostream>
using namespace std;

Grid::Grid() : numRows{6}, numCols{6}, cellSize{30} { Initialization(); colors = getCellColors(); }

void Grid::Initialization()
{
    for(int i = 0; i < numRows * 6; i++)
    {
        for(int j = 0; j < numCols * 6; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Grid::Draw()
{
    for(int i = 0; i < numRows * 6; i++)
    {
        for(int j = 0; j < numCols * 6; j++)
        {
            int cellValue = grid[i][j];
            DrawRectangle(j * cellSize+1, i * cellSize+1, cellSize-1, cellSize-1, colors[cellValue]); 
        }
    }
}

void Grid::Print()
{
    for(int i = 0; i < numRows * 6; i+= 6)
    {
        for(int j = 0; j < numCols * 6; j+= 6)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}