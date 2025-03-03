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
    void setInitialPosition(int row = 0, int col = 0);
    vector<Position> getCellPositions();
    int getRotationState();
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
    void rotateRight();
    void rotateLeft();
};
