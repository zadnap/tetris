#pragma once
#include "board.h"
#include "tetromino.h"
#include "../src/tetrominoes.cpp"
#include "utils.h"
#include "colors.h"
#include <cmath>
#include <raylib.h>
#include <random>

class Game
{
private:
    int score;
    int level;
    int totalClearedRows;
    bool gameOver;
    double lockTimer;
    static constexpr double LOCK_DELAY = 0.5;
    Board board;
    vector<Tetromino> tetrominoes;
    vector<Tetromino> getTetrominoes();
    Tetromino currentTetromino;
    Tetromino nextTetromino;
    Tetromino getRandomTetromino();
    bool isCurrentTetroOutsideGrid();
    bool isCurrentTetroOverlapping();
    int getKickIndex(int from, int to);
    bool tryWallkick(int from, int to);
    void lockTetromino();
    void updateScore(int rowsCleared);
    void updateLevel();
    void loadNextTetromino();
    void startNew();

public:
    Game();
    void runGameLoop();
    bool isGameOver();
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
    void restart();
};
