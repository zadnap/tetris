#pragma once
#include <raylib.h>
#include <vector>
using namespace std;

extern const Color TEXT_COLOR;
extern const Color BACKGROUND_COLOR;
extern const Color GRID_COLOR;
extern const Color I_TETROMINO_COLOR;
extern const Color O_TETROMINO_COLOR;
extern const Color T_TETROMINO_COLOR;
extern const Color L_TETROMINO_COLOR;
extern const Color J_TETROMINO_COLOR;
extern const Color S_TETROMINO_COLOR;
extern const Color Z_TETROMINO_COLOR;

vector<Color> getCellColors();