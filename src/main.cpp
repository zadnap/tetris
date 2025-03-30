#include "../include/game.h"
#include "../include/inputHandler.h"
#include "../include/userInterface.h"
#include "../include/colors.h"
#include <raylib.h>
#include <cmath>

bool hasElapsedTime(double interval, double &lastUpdateTime);

int main()
{
    Game game = Game();
    InputHandler inputHandler = InputHandler(game);
    UserInterface userInterface = UserInterface(game);

    double lastUpdateOnMovingDown = 0;

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
            if (hasElapsedTime(0.8 * pow(0.85, game.getLevel()), lastUpdateOnMovingDown))
                game.moveTetrominoDown();
            inputHandler.handleMovement();
        }

        EndDrawing();
    }

    return 0;
}

bool hasElapsedTime(double interval, double &lastUpdateTime)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}