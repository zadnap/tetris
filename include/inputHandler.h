#pragma once
#include "game.h"
#include <raylib.h>

class InputHandler
{
private:
    Game &game;

    int dasDirection;
    double dasDelay;
    double dasRepeatRate;
    double keyPressStartTime;
    double lastMoveTime;

    void handleNormalMovement();
    void handleDasMovement(int direction, bool isVertical);

public:
    InputHandler(Game &game);
    void handleMovement();
    void handleGameMenu();
};
