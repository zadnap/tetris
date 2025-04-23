#include "../include/userInterface.h"

UserInterface::UserInterface(Game &game) : game(game)
{
    cellSize = 30;
    gridGap = 2;
    sidebarWidth = 150;
    margin = 30;
    textBlockHeight = 90;
    fontSize = 20;
    blockPadding = 15;
}

void UserInterface::initWindow()
{
    Board &board = game.getBoard();
    gridWidth = board.getNumCols() * cellSize;
    float gridHeight = board.getNumRows() * cellSize;

    windowWidth = gridWidth + margin * 3 + sidebarWidth;
    windowHeight = gridHeight + margin * 2;

    InitWindow(windowWidth, windowHeight, "Tetris");
    SetTargetFPS(game.getFPS());

    Image icon = LoadImage("assets/icon/icon.png");
    SetWindowIcon(icon);
    UnloadImage(icon);
}

void UserInterface::drawMainScreen()
{
    drawGrid();
    drawCurrentTetromino();
    drawTextBlock(gridWidth + margin * 2, margin, "Score", to_string(game.getScore()));
    drawTextBlock(gridWidth + margin * 2, margin * 1.5 + textBlockHeight, "Level", to_string(game.getLevel()));
    drawNextTetromino();
    drawPauseText();
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
    Rectangle scoreBlock = {
        offsetX,
        offsetY,
        sidebarWidth,
        textBlockHeight,
    };

    DrawRectangleRounded(scoreBlock, 0.1f, 10, GRID_COLOR);

    int textBlockLabelWidth = MeasureText(label.c_str(), fontSize);
    float labelX = offsetX + (scoreBlock.width - textBlockLabelWidth) / 2;
    float labelY = offsetY + blockPadding;

    DrawText(label.c_str(), labelX, labelY, fontSize, TEXT_COLOR);

    int textBlockContentWidth = MeasureText(content.c_str(), fontSize);
    float textBlockContentX = offsetX + (scoreBlock.width - textBlockContentWidth) / 2;
    float textBlockContentY = offsetY + textBlockHeight - blockPadding * 2.5;

    DrawText(content.c_str(), textBlockContentX, textBlockContentY, fontSize, TEXT_COLOR);
}

void UserInterface::drawNextTetromino()
{
    float nextTetroX = gridWidth + margin * 2;
    float nextTetroY = margin * 2 + textBlockHeight * 2;

    float nextTetroHeight = 150;

    Rectangle nextTetroBlock = {nextTetroX, nextTetroY, sidebarWidth, nextTetroHeight};
    DrawRectangleRounded(nextTetroBlock, 0.1f, 10, GRID_COLOR);

    string nextTetroLabel = "Incoming";
    int nextTetroLabelWidth = MeasureText(nextTetroLabel.c_str(), fontSize);
    float nextTetroLabelX = nextTetroX + (nextTetroBlock.width - nextTetroLabelWidth) / 2;
    float nextTetroLabelY = nextTetroY + blockPadding;

    DrawText(nextTetroLabel.c_str(), nextTetroLabelX, nextTetroLabelY, fontSize, TEXT_COLOR);

    Tetromino currentTetromino = game.getNextTetromino();
    vector<Position> cellPositions = currentTetromino.getCellPositions();

    int leftMost = cellPositions[0].col;
    int rightMost = cellPositions[0].col;
    for (Position cellPos : cellPositions)
    {
        if (cellPos.col > rightMost)
            rightMost = cellPos.col;
        if (cellPos.col < leftMost)
            leftMost = cellPos.col;
    }

    float tetroWidth = (rightMost - leftMost + 1) * cellSize;
    float nextTetroImageX = nextTetroX + (nextTetroBlock.width - tetroWidth) / 2;
    float nextTetroImageY = nextTetroY + fontSize + blockPadding * 3;

    for (Position cellPos : cellPositions)
    {
        Rectangle cell = {
            nextTetroImageX + (cellPos.col - leftMost) * cellSize + gridGap,
            nextTetroImageY + cellPos.row * cellSize + gridGap,
            cellSize - gridGap,
            cellSize - gridGap,
        };
        DrawRectangleRounded(cell, 0.2f, 10, getCellColors()[currentTetromino.id]);
    }
}

void UserInterface::drawGameMenu(string label, vector<string> text)
{
    DrawRectangle(0, 0, windowWidth, windowHeight, OVERLAY_COLOR);

    float textSpace = 30;
    float textPadding = 10;
    float gameOverY = (windowHeight - 4 * fontSize - 4 * textSpace) / 2;

    int labelWidth = MeasureText(label.c_str(), fontSize * 2);
    DrawText(label.c_str(), (windowWidth - labelWidth) / 2, gameOverY, fontSize * 2, HEADING_COLOR);

    for (size_t i = 0; i < text.size(); i++)
    {
        int textWidth = MeasureText(text[i].c_str(), fontSize);
        Color textColor = TEXT_COLOR;
        double space = textSpace * (i + 2);

        if (i == text.size() - 1)
        {
            space += textPadding;
            textColor = BUTTON_COLOR;
        }

        DrawText(text[i].c_str(), (windowWidth - textWidth) / 2, gameOverY + textPadding + space, fontSize, textColor);
    }
}

void UserInterface::drawPauseText()
{
    const char *text = "Pause [P]";
    int textWidth = MeasureText(text, fontSize);
    DrawText(text, windowWidth - textWidth - margin, windowHeight - fontSize - margin, fontSize, TEXT_COLOR);
}