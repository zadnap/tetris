#pragma once
#include "game.h"

class UserInterface
{
private:
    Game &game;

public:
    UserInterface(Game &game);
    void initWindow();
    void drawGrid();
    void drawCurrentTetromino();
};
