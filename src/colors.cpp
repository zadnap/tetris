#include "../include/colors.h"
#include <raylib.h>
#include <vector>
using namespace std;

Color TEXT_COLOR = {255, 255, 255, 255};
Color BACKGROUND_COLOR = {38, 43, 57, 1};
Color TETROMINO_I_COLOR = {0, 240, 240, 255};
Color TETROMINO_O_COLOR = {240, 240, 0, 255};
Color TETROMINO_T_COLOR = {160, 0, 240, 255};
Color TETROMINO_L_COLOR = {240, 160, 0, 255};
Color TETROMINO_J_COLOR = {0, 0, 240, 255};
Color TETROMINO_S_COLOR = {0, 240, 0, 255};
Color TETROMINO_Z_COLOR = {240, 0, 0, 255};

vector<Color> getCellColors()
{
    return {BACKGROUND_COLOR, TETROMINO_I_COLOR, TETROMINO_O_COLOR, TETROMINO_T_COLOR, TETROMINO_L_COLOR, TETROMINO_J_COLOR, TETROMINO_S_COLOR, TETROMINO_Z_COLOR};
}