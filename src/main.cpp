#include "../include/game.h"
#include "../include/inputHandler.h"
#include "../include/userInterface.h"
#include "../include/audioHandler.h"

int main()
{
    Game game;
    InputHandler inputHandler(game);
    UserInterface userInterface(game);
    AudioHandler audioHandler;

    double lastUpdateOnMovingDown = GetTime();
    userInterface.initWindow();

    audioHandler.loadMusic("background", "assets/audio/background-music.mp3");
    audioHandler.loadSound("rotate", "assets/audio/rotating-sound.ogg");
    audioHandler.loadSound("place", "assets/audio/placing-sound.ogg");
    audioHandler.loadSound("clear", "assets/audio/clearing-sound.ogg");

    audioHandler.playBackgroundMusic("background", 0.3f);
    game.onRotate = [&]()
    { audioHandler.playSoundEffect("rotate", 3.0f); };
    game.onPlace = [&]()
    { audioHandler.playSoundEffect("place", 6.0f); };
    game.onClear = [&](int clearedRows)
    { audioHandler.playSoundEffect("clear", clearedRows * 2.0f); };

    while (!WindowShouldClose())
    {
        audioHandler.update();

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