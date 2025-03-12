#pragma once
#include "game.h"
#include <string>

class UserInterface
{
private:
    Game &game;
    float cellSize;
    float gridGap;
    float gridWidth;
    float margin;
    float sidebarWidth;
    float textBlockHeight;
    float fontSize;
    float blockPadding;
    void drawGrid();
    void drawCurrentTetromino();
    void drawTextBlock(float offsetX, float offsetY, string label, string content);
    void drawNextTetromino();

public:
    UserInterface(Game &game);
    void initWindow();
    void drawScreen();
};
