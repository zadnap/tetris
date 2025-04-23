#pragma once
#include "game.h"
#include "colors.h"
#include <string>
#include <raylib.h>

class UserInterface
{
private:
    Game &game;
    int windowWidth;
    int windowHeight;
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
    void drawPauseText();

public:
    UserInterface(Game &game);
    void initWindow();
    void drawGameMenu(string label, vector<string> text1, vector<string> text2);
    void drawMainScreen();
};
