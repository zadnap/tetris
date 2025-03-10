#include "../include/userInterface.h"
#include "../include/colors.h"
#include <raylib.h>

const float CELL_SIZE = 30;
const float GRID_GAP = 2;

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
            Rectangle cell = {
                col * CELL_SIZE + GRID_GAP,
                row * CELL_SIZE + GRID_GAP,
                CELL_SIZE - GRID_GAP,
                CELL_SIZE - GRID_GAP,
            };
            DrawRectangleRounded(cell, 0.2f, 10, cellColors[board.getCell(row, col)]);
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
        Rectangle cell = {
            tetrominoPositions[i].col * CELL_SIZE + GRID_GAP,
            tetrominoPositions[i].row * CELL_SIZE + GRID_GAP,
            CELL_SIZE - GRID_GAP,
            CELL_SIZE - GRID_GAP,
        };
        DrawRectangleRounded(cell, 0.2f, 10, cellColors[currentTetromino.id]);
    }
}