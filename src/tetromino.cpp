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

void Tetromino::move(int rowDelta, int colDelta)
{
    rowOffset += rowDelta;
    colOffset += colDelta;
}

void Tetromino::rotate()
{
    rotationState = (rotationState + 1) % rotations.size();
}
