#include "../include/inputHandler.h"

InputHandler::InputHandler(Game &game) : game(game)
{
    dasDirection = 0;
    dasDelay = 0.2;
    dasRepeatRate = 0.05;
    lastMoveTime = 0.0;
    keyPressStartTime = 0.0;
}

void InputHandler::handleMovement()
{
    handleNormalMovement();
    handleDasMovement(-1, false);
    handleDasMovement(1, false);
    handleDasMovement(1, true);
}

void InputHandler::handleNormalMovement()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_SPACE:
        game.hardDropTetromino();
        break;
    case KEY_Z:
        game.rotateTetrominoLeft();
        break;
    case KEY_X:
        game.rotateTetrominoRight();
        break;
    }
}

void InputHandler::handleDasMovement(int direction, bool isVertical = false)
{
    double currentTime = GetTime();
    int key = isVertical ? KEY_DOWN : (direction == 1 ? KEY_RIGHT : KEY_LEFT);
    bool isMoving = (isVertical ? IsKeyPressed(KEY_DOWN) : (direction == -1 ? IsKeyPressed(KEY_LEFT) : IsKeyPressed(KEY_RIGHT)));

    if (isMoving)
    {
        if (isVertical)
            game.moveTetrominoDown();
        else
            (direction == -1 ? game.moveTetrominoLeft() : game.moveTetrominoRight());

        dasDirection = direction;
        keyPressStartTime = currentTime;
        lastMoveTime = currentTime;
    }

    if (IsKeyDown(key) && dasDirection == direction)
    {
        if (currentTime - keyPressStartTime >= dasDelay && currentTime - lastMoveTime >= dasRepeatRate)
        {
            if (isVertical)
                game.moveTetrominoDown();
            else
                (direction == -1 ? game.moveTetrominoLeft() : game.moveTetrominoRight());

            lastMoveTime = currentTime;
        }
    }
}

void InputHandler::handleGameMenu()
{
    int keyPressed = GetKeyPressed();

    switch (keyPressed)
    {
    case KEY_ENTER:
        game.startNew();
        break;
    }
}