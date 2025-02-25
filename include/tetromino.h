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
    vector<Position> getCellPositions();
    void move(int rowDelta, int colDelta);
    void rotateRight();
    void rotateLeft();
};
