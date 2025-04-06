#include "../include/game.h"
#include "../include/inputHandler.h"
#include "../include/userInterface.h"

int main()
{
    Game game;
    InputHandler inputHandler(game);
    UserInterface userInterface(game);

    double lastUpdateOnMovingDown = GetTime();
    userInterface.initWindow();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        userInterface.drawMainScreen();

        if (game.isGameOver())
        {
            userInterface.drawGameMenu();
            inputHandler.handleGameMenu();
        }
        else
        {
            double droppingSpeed = 0.8 * pow(0.85, game.getLevel());
            if (hasElapsedTime(droppingSpeed, lastUpdateOnMovingDown))
                game.moveTetrominoDown();

            inputHandler.handleMovement();
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}