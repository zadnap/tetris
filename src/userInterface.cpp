#include "../include/userInterface.h"
#include "../include/colors.h"
#include <raylib.h>
#include <string>

UserInterface::UserInterface(Game &game) : game(game)
{
    cellSize = 30;
    gridGap = 2;
    sidebarWidth = 150;
    margin = 30;
    textBlockHeight = 90;
    fontSize = 20;
}

void UserInterface::initWindow()
{
    Board &board = game.getBoard();
    gridWidth = board.getNumCols() * cellSize;
    float gridHeight = board.getNumRows() * cellSize;

    int windowWidth = gridWidth + margin * 3 + sidebarWidth;
    int windowHeight = gridHeight + margin * 2;

    InitWindow(windowWidth, windowHeight, "Tetris");
}

void UserInterface::drawScreen()
{
    drawGrid();
    drawCurrentTetromino();
    drawTextBlock(gridWidth + margin * 2, margin, "Score", to_string(game.getScore()));
    drawTextBlock(gridWidth + margin * 2, margin * 1.5 + textBlockHeight, "Level", to_string(game.getLevel()));
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
                margin + col * cellSize + gridGap,
                margin + row * cellSize + gridGap,
                cellSize - gridGap,
                cellSize - gridGap,
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
            margin + tetrominoPositions[i].col * cellSize + gridGap,
            margin + tetrominoPositions[i].row * cellSize + gridGap,
            cellSize - gridGap,
            cellSize - gridGap,
        };
        DrawRectangleRounded(cell, 0.2f, 10, cellColors[currentTetromino.id]);
    }
}

void UserInterface::drawTextBlock(float offsetX, float offsetY, string label, string content)
{
    float textBlockPadding = 20;

    Rectangle scoreBlock = {
        offsetX,
        offsetY,
        sidebarWidth,
        textBlockHeight,
    };

    DrawRectangleRounded(scoreBlock, 0.1f, 10, GRID_COLOR);

    int textBlockLabelWidth = MeasureText(label.c_str(), fontSize);
    float labelX = offsetX + (scoreBlock.width - textBlockLabelWidth) / 2;
    float labelY = offsetY + textBlockPadding;

    DrawText(label.c_str(), labelX, labelY, fontSize, TEXT_COLOR);

    int textBlockContentWidth = MeasureText(content.c_str(), fontSize);
    float textBlockContentX = offsetX + (scoreBlock.width - textBlockContentWidth) / 2;
    float textBlockContentY = offsetY + textBlockHeight - textBlockPadding * 2;

    DrawText(content.c_str(), textBlockContentX, textBlockContentY, fontSize, TEXT_COLOR);
}

void UserInterface::drawNextTetromino()
{
}
