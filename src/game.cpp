#include "../include/game.h"
#include "tetrominoes.cpp"
#include <random>

Game::Game()
{
    score = 0;
    gameOver = false;
    board = Board();
    tetrominoes = getTetrominoes();
    currentTetromino = getRandomTetromino();
    nextTetromino = getRandomTetromino();
}

bool Game::isGameOver()
{
    return gameOver;
}

int Game::getScore()
{
    return score;
}

Board &Game::getBoard()
{
    return board;
}

Tetromino Game::getRandomTetromino()
{
    if (tetrominoes.empty())
    {
        tetrominoes = getTetrominoes();
    }

    int randomIndex = rand() % tetrominoes.size();
    Tetromino randomTetromino = tetrominoes[randomIndex];
    tetrominoes.erase(tetrominoes.begin() + randomIndex);

    return randomTetromino;
}

vector<Tetromino> Game::getTetrominoes()
{
    return {ITetromino(), OTetromino(), TTetromino(), LTetromino(), JTetromino(), STetromino(), ZTetromino()};
}

Tetromino Game::getCurrentTetromino()
{
    return currentTetromino;
}

Tetromino Game::getNextTetromino()
{
    return nextTetromino;
}

bool Game::isCurrentTetroOutsideGrid()
{
    vector<Position> cellPositions = currentTetromino.getCellPositions();
    for (Position cellPos : cellPositions)
    {
        if (!board.isWithinBounds(cellPos.row, cellPos.col))
            return true;
    }
    return false;
}

bool Game::isCurrentTetroOverlapping()
{
    vector<Position> cellPositions = currentTetromino.getCellPositions();
    for (Position cellPos : cellPositions)
    {
        if (!board.canPlace(cellPos.row, cellPos.col))
            return true;
    }
    return false;
}

void Game::moveTetrominoLeft()
{
    currentTetromino.move(0, -1);
    if (isCurrentTetroOutsideGrid() || isCurrentTetroOverlapping())
        currentTetromino.move(0, 1);
}

void Game::moveTetrominoRight()
{
    currentTetromino.move(0, 1);
    if (isCurrentTetroOutsideGrid() || isCurrentTetroOverlapping())
        currentTetromino.move(0, -1);
}

void Game::moveTetrominoDown()
{
    currentTetromino.move(1, 0);
    if (isCurrentTetroOutsideGrid() || isCurrentTetroOverlapping())
        currentTetromino.move(-1, 0);
}
