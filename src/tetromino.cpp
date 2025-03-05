#include "../include/tetromino.h"

Tetromino::Tetromino()
{
    rowOffset = 0;
    colOffset = 0;
    rotationState = 0;
}

vector<Position> Tetromino::getCellPositions()
{
    vector<Position> currentRotation = rotations[rotationState];
    vector<Position> cellPositions;

    for (Position cell : currentRotation)
        cellPositions.push_back(Position(cell.row + rowOffset, cell.col + colOffset));

    return cellPositions;
}

int Tetromino::getRotationState() const
{
    return rotationState;
}

void Tetromino::move(int rowShift, int colShift)
{
    rowOffset += rowShift;
    colOffset += colShift;
}

void Tetromino::rotateRight()
{
    rotationState = (rotationState + 1) % rotations.size();
}

void Tetromino::rotateLeft()
{
    rotationState = (rotationState - 1 + rotations.size()) % rotations.size();
}
