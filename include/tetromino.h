#pragma once
#include "../include/position.h"
#include <vector>
#include <map>
using namespace std;

class Tetromino
{
private:
    int rowOffset;
    int colOffset;
    int rotationState;

public:
    Tetromino();
    int id;
    map<int, vector<Position>> rotations;
    map<int, vector<Position>> wallkickOffsets;
    vector<Position> getCellPositions();
    int getRotationState() const;
    void move(int rowShift, int colShift);
    int rotateRight();
    int rotateLeft();
};
