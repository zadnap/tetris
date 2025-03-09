#pragma once
#include "game.h"

class UserInterface
{
private:
    Game &game;
    void drawGrid();
    void drawCurrentTetromino();

public:
    UserInterface(Game &game);
    void initWindow();
    void drawScreen();
};
