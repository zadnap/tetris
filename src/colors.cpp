#include "../include/colors.h"
#include <raylib.h>
#include <vector>
using namespace std;

const Color TEXT_COLOR = {255, 255, 255, 255};
const Color BACKGROUND_COLOR = {38, 43, 57, 1};
const Color I_TETROMINO_COLOR = {0, 240, 240, 255};
const Color O_TETROMINO_COLOR = {240, 240, 0, 255};
const Color T_TETROMINO_COLOR = {160, 0, 240, 255};
const Color L_TETROMINO_COLOR = {240, 160, 0, 255};
const Color J_TETROMINO_COLOR = {0, 0, 240, 255};
const Color S_TETROMINO_COLOR = {0, 240, 0, 255};
const Color Z_TETROMINO_COLOR = {240, 0, 0, 255};

vector<Color> getCellColors()
{
    return {BACKGROUND_COLOR, I_TETROMINO_COLOR, O_TETROMINO_COLOR, T_TETROMINO_COLOR, L_TETROMINO_COLOR, J_TETROMINO_COLOR, S_TETROMINO_COLOR, Z_TETROMINO_COLOR};
}