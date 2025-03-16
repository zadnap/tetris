#pragma once
#include "game.h"

class InputHandler
{
private:
    Game &game;

public:
    InputHandler(Game &game);
    void handleMovement();
    void handleGameMenu();
};
