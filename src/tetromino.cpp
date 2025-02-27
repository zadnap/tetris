#include "../include/tetromino.h"

Tetromino::Tetromino()
{
    setInitialPosition();
    rotationState = 0;
}

void Tetromino::setInitialPosition(int row, int col)
{
    rowOffset = row;
    colOffset = col;
}

vector<Position> Tetromino::getCellPositions()
{
    vector<Position> currentRotation = rotations[rotationState];
    vector<Position> cellPositions;

    for (Position cell : currentRotation)
        cellPositions.push_back(Position(cell.row + rowOffset, cell.col + colOffset));

    return cellPositions;
}

void Tetromino::moveLeft()
{
    colOffset--;
}

void Tetromino::moveRight()
{
    colOffset++;
}

void Tetromino::moveDown()
{
    rowOffset--;
}

void Tetromino::moveUp()
{
    rowOffset++;
}

void Tetromino::rotateRight()
{
    rotationState = (rotationState + 1) % rotations.size();
}

void Tetromino::rotateLeft()
{
    rotationState = (rotationState - 1 + rotations.size()) % rotations.size();
}
