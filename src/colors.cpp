#include "colors.h"

const Color black = {0, 0, 0, 255}; 
const Color white = {255, 255, 255, 255};
const Color red = {232, 18, 18, 255}; 
const Color orange = {226, 116, 17, 255}; 
const Color yellow = {166, 0, 247, 255}; 
const Color purple = {21, 204, 209, 255}; 



std::vector<Color> getCellColors()
{
    return {black, white, red, orange, yellow, purple};
}