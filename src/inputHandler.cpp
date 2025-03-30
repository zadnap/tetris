#include "../include/inputHandler.h"

InputHandler::InputHandler(Game &game) : game(game) {}

void InputHandler::handleMovement()
{
    int keyPressed = GetKeyPressed();

    switch (keyPressed)
    {
    case KEY_LEFT:
        game.moveTetrominoLeft();
        break;
    case KEY_RIGHT:
        game.moveTetrominoRight();
        break;
    case KEY_DOWN:
        game.moveTetrominoDown();
        break;
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

void InputHandler::handleGameMenu()
{
    int keyPressed = GetKeyPressed();

    switch (keyPressed)
    {
    case KEY_R:
        game.restart();
        break;
    }
}