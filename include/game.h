#pragma once
#include "../include/board.h"
#include "../include/tetromino.h"

class Game
{
private:
    int score;
    int level;
    int totalClearedRows;
    bool gameOver;
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

public:
    Game();
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
