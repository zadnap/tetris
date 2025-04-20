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

    audioHandler.loadMusic("background", "background.mp3");
    audioHandler.loadSound("gameOver", "game-over.mp3");
    audioHandler.loadSound("rotate", "rotate.ogg");
    audioHandler.loadSound("place", "place.ogg");
    audioHandler.loadSound("clear", "clear.ogg");

    game.onStart = [&]()
    { audioHandler.playBackgroundMusic("background", 0.3f); };
    game.onEnd = [&]()
    {
        audioHandler.stopBackgroundMusic();
        audioHandler.playSoundEffect("gameOver", 3.0f);
    };
    game.onRotate = [&]()
    { audioHandler.playSoundEffect("rotate", 2.0f); };
    game.onPlace = [&]()
    { audioHandler.playSoundEffect("place", 4.0f); };
    game.onClear = [&](int clearedRows)
    { audioHandler.playSoundEffect("clear", clearedRows * 2.0f); };

    userInterface.initWindow();
    while (!WindowShouldClose())
    {
        audioHandler.update();

        BeginDrawing();

        ClearBackground(BACKGROUND_COLOR);

        if (game.getState() == GameState::NotStarted)
        {
            userInterface.drawGameMenu("TETRIS", {"High Score: " + to_string(game.getHighScore()), "Start [Enter]"});
            inputHandler.handleGameMenu();
        }
        else if (game.getState() == GameState::GameOver)
        {
            userInterface.drawMainScreen();
            userInterface.drawGameMenu("BOOYAH!", {"Final Score: " + to_string(game.getScore()), "High Score: " + to_string(game.getHighScore()), "Restart [Enter]"});
            inputHandler.handleGameMenu();
        }
        else
        {
            userInterface.drawMainScreen();

            if (hasElapsedTime(game.getDropSpeed(), lastUpdateOnMovingDown))
                game.moveTetrominoDown();

            inputHandler.handleMovement();
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}