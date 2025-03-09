#include "../include/userInterface.h"
#include "../include/colors.h"
#include <raylib.h>

const int CELL_SIZE = 30;

UserInterface::UserInterface(Game &game) : game(game) {}

void UserInterface::initWindow()
{
    Board &board = game.getBoard();
    int gridWidth = board.getNumCols() * CELL_SIZE;
    int gridHeight = board.getNumRows() * CELL_SIZE;
    InitWindow(gridWidth, gridHeight, "Tetris");
}

void UserInterface::drawScreen()
{
    drawGrid();
    drawCurrentTetromino();
}

void UserInterface::drawGrid()
{
    Board &board = game.getBoard();
    vector<Color> cellColors = getCellColors();

    for (int row = 0; row < board.getNumRows(); row++)
    {
        for (int col = 0; col < board.getNumCols(); col++)
        {
            DrawRectangle(
                col * CELL_SIZE + 1,
                row * CELL_SIZE + 1,
                CELL_SIZE - 1,
                CELL_SIZE - 1,
                cellColors[board.getCell(row, col)]);
        }
    }
}

void UserInterface::drawCurrentTetromino()
{
    vector<Color> cellColors = getCellColors();
    Tetromino currentTetromino = game.getCurrentTetromino();
    vector<Position> tetrominoPositions = currentTetromino.getCellPositions();

    for (size_t i = 0; i < tetrominoPositions.size(); i++)
    {
        DrawRectangle(
            tetrominoPositions[i].col * CELL_SIZE + 1,
            tetrominoPositions[i].row * CELL_SIZE + 1,
            CELL_SIZE - 1,
            CELL_SIZE - 1,
            cellColors[currentTetromino.id]);
    }
}