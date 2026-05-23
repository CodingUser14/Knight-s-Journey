#pragma once
#include <raylib.h>
#include <vector>

extern const Color light; // extern allows to use it in another file and const implies it cannot be changed
extern const Color dark;
extern const Color red; 
extern const Color orange; 
extern const Color yellow; 
extern const Color black; 

std::vector<Color> getCellColors();