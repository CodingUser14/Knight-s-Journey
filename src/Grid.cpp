#include "Grid.h"
#include "colors.h"
#include <iostream>
using namespace std;

Grid::Grid() : numRows{5}, numCols{5}, cellSize{100} { Initialization(); colors = getCellColors(); }

void Grid::Initialization()
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if((i + j) % 2 == 0)
            {
                grid[i][j] = 0; // black
            }
            else
            {
                grid[i][j] = 1; // white
            }
        }
    }
}

void Grid::Draw()
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            int cellValue = grid[i][j];
            DrawRectangle(j * cellSize, i * cellSize, cellSize, cellSize, colors[cellValue]); 
            // (1,1 100,100) (101,101 200,200)  
        }
    }
}

void Grid::Print()
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}