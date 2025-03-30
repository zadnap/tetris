#pragma once
#include "game.h"
#include <raylib.h>

class InputHandler
{
private:
    Game &game;

public:
    InputHandler(Game &game);
    void handleMovement();
    void handleGameMenu();
};
