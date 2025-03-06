#include "../include/tetromino.h"

Tetromino::Tetromino()
{
    rowOffset = 0;
    colOffset = 0;
    rotationState = 0;
    wallkickOffsets[0] = {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}};
    wallkickOffsets[1] = {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}};
    wallkickOffsets[2] = {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}};
    wallkickOffsets[3] = {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}};
    wallkickOffsets[4] = {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}};
    wallkickOffsets[5] = {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}};
    wallkickOffsets[6] = {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}};
    wallkickOffsets[7] = {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}};
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

int Tetromino::rotateRight()
{
    int prevRotationState = rotationState;
    rotationState = (rotationState + 1) % rotations.size();
    return prevRotationState;
}

int Tetromino::rotateLeft()
{
    int prevRotationState = rotationState;
    rotationState = (rotationState - 1 + rotations.size()) % rotations.size();
    return prevRotationState;
}
