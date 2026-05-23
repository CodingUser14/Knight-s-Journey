#include "colors.h"

const Color light = {240, 217, 181, 255}; 
const Color dark = {181, 136, 99, 255};
const Color red = {232, 18, 18, 255}; 
const Color orange = {226, 116, 17, 255}; 
const Color yellow = {166, 0, 247, 255}; 
const Color black = {0, 0, 0, 255};

std::vector<Color> getCellColors()
{
    return {light, dark, red, orange, yellow, black};
}