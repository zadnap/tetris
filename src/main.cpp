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
    game.onPause = [&]()
    { audioHandler.pauseBackgroundMusic(); };
    game.onResume = [&]()
    { audioHandler.resumeBackgroundMusic(); };
    game.onEnd = [&]()
    {
        audioHandler.stopBackgroundMusic();
        audioHandler.playSoundEffect("gameOver", 3.0f);
    };
    game.onRotate = [&]()
    { audioHandler.playSoundEffect("rotate", 0.5f); };
    game.onPlace = [&]()
    { audioHandler.playSoundEffect("place", 2.0f); };
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
            userInterface.drawGameMenu("TETRIS", {"High Score: " + to_string(game.getHighScore()), "Start [S]"});
            inputHandler.handleGameMenu("start");
        }
        else if (game.getState() == GameState::Paused)
        {
            userInterface.drawMainScreen();
            userInterface.drawGameMenu("TETRIS", {"Score: " + to_string(game.getScore()), "Continue [C]"});
            inputHandler.handleGameMenu("pause");
        }
        else if (game.getState() == GameState::GameOver)
        {
            userInterface.drawMainScreen();
            userInterface.drawGameMenu("BOOYAH!", {"Final Score: " + to_string(game.getScore()), "High Score: " + to_string(game.getHighScore()), "Restart [R]"});
            inputHandler.handleGameMenu("end");
        }
        else
        {
            userInterface.drawMainScreen();

            if (hasElapsedTime(game.getDropSpeed(), lastUpdateOnMovingDown))
                game.moveTetrominoDown();

            inputHandler.handleGamePlay();
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}