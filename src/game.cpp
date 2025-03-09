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

int generateRandomNumber(int min, int max)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

Tetromino Game::getRandomTetromino()
{
    if (tetrominoes.empty())
    {
        tetrominoes = getTetrominoes();
    }

    int randomIndex = generateRandomNumber(0, tetrominoes.size() - 1);
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
    {
        currentTetromino.move(-1, 0);
        lockTetromino();
    }
}

bool Game::tryWallkick(int from, int to)
{
    int kickIndex = getKickIndex(from, to);
    vector<Position> trials = currentTetromino.wallkickOffsets[kickIndex];

    for (Position offset : trials)
    {
        currentTetromino.move(offset.row, offset.col);

        if (!isCurrentTetroOutsideGrid() && !isCurrentTetroOverlapping())
            return true;

        currentTetromino.move(-offset.row, -offset.col);
    }

    return false;
}

int Game::getKickIndex(int from, int to)
{
    if (from == 0 && to == 1)
        return 0;
    if (from == 1 && to == 0)
        return 1;
    if (from == 1 && to == 2)
        return 2;
    if (from == 2 && to == 1)
        return 3;
    if (from == 2 && to == 3)
        return 4;
    if (from == 3 && to == 2)
        return 5;
    if (from == 3 && to == 0)
        return 6;
    if (from == 0 && to == 3)
        return 7;
    return -1;
}

void Game::rotateTetrominoLeft()
{
    int prevState = currentTetromino.rotateLeft();
    if (!tryWallkick(prevState, currentTetromino.getRotationState()))
        currentTetromino.rotateRight();
}

void Game::rotateTetrominoRight()
{
    int prevState = currentTetromino.rotateRight();
    if (!tryWallkick(prevState, currentTetromino.getRotationState()))
        currentTetromino.rotateLeft();
}

void Game::lockTetromino()
{
    vector<Position> cellPositions = currentTetromino.getCellPositions();
    for (Position cellPos : cellPositions)
    {
        if (!board.isWithinBounds(cellPos.row, cellPos.col) || !board.canPlace(cellPos.row, cellPos.col))
        {
            gameOver = true;
            return;
        }
        board.setCell(cellPos.row, cellPos.col, currentTetromino.id);
    }

    if (board.isFull())
    {
        gameOver = true;
        return;
    }

    updateScore(board.clearCompleteRows());
    currentTetromino = nextTetromino;
    nextTetromino = getRandomTetromino();
}

void Game::hardDropTetromino()
{
    while (true)
    {
        currentTetromino.move(1, 0);
        if (isCurrentTetroOutsideGrid() || isCurrentTetroOverlapping())
        {
            currentTetromino.move(-1, 0);
            lockTetromino();
            break;
        }
    }
}

void Game::updateScore(int rowsCleared)
{
    switch (rowsCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    case 4:
        score += 800;
        break;
    }
}