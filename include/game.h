#pragma once
#include "board.h"
#include "tetromino.h"
#include "../src/tetrominoes.cpp"
#include "utils.h"
#include <cmath>
#include <raylib.h>
#include <random>
#include <functional>
#include <filesystem>
#include <fstream>
using namespace std;

enum class GameState
{
    NotStarted,
    Playing,
    Paused,
    GameOver
};

class Game
{
private:
    int score;
    int level;
    int totalClearedRows;
    int fps;
    GameState state = GameState::NotStarted;
    double lockTimer;
    static constexpr double LOCK_DELAY = 0.5;
    Board board;
    vector<Tetromino> tetrominoes;
    vector<Tetromino> getTetrominoes();
    Tetromino currentTetromino;
    Tetromino nextTetromino;
    Tetromino getRandomTetromino();
    const vector<int> framesPerCell = {
        48, 43, 38, 33, 28, 23, 18, 13, 8, 6, 5, 5, 5, 4, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1};
    bool isCurrentTetroOutsideGrid();
    bool isCurrentTetroOverlapping();
    int getKickIndex(int from, int to);
    bool tryWallkick(int from, int to);
    void lockTetromino();
    void updateScore(int rowsCleared);
    void updateLevel();
    void endGame();
    void loadNextTetromino();
    void ensureSaveFolder();
    void saveHighScore(int score);

public:
    void startGame();
    void pauseGame();
    void resumeGame();
    int getFPS();
    GameState getState();
    int getScore();
    int getLevel();
    Board &getBoard();
    Tetromino getCurrentTetromino();
    Tetromino getNextTetromino();
    void moveTetrominoLeft();
    void moveTetrominoRight();
    void moveTetrominoDown();
    void rotateTetrominoLeft();
    void rotateTetrominoRight();
    void hardDropTetromino();
    int getHighScore();
    double getDropSpeed();
    function<void()> onRotate;
    function<void()> onPlace;
    function<void(int)> onClear;
    function<void()> onStart;
    function<void()> onEnd;
    function<void()> onPause;
    function<void()> onResume;
};
