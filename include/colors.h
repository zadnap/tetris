#pragma once
#include <raylib.h>
#include <vector>
using namespace std;

extern const Color TEXT_COLOR;
extern const Color BACKGROUND_COLOR;
extern const Color TETROMINO_I_COLOR;
extern const Color TETROMINO_O_COLOR;
extern const Color TETROMINO_T_COLOR;
extern const Color TETROMINO_L_COLOR;
extern const Color TETROMINO_J_COLOR;
extern const Color TETROMINO_S_COLOR;
extern const Color TETROMINO_Z_COLOR;

vector<Color> getCellColors();