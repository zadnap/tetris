#include "../include/tetromino.h"
#include "../include/position.h"

class ITetromino : public Tetromino
{
public:
    ITetromino()
    {
        id = 1;
        rotations[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
        rotations[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
        rotations[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
        rotations[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        setInitialPosition(0, 3);
    }
};

class OTetromino : public Tetromino
{
public:
    OTetromino()
    {
        id = 2;
        rotations[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        setInitialPosition(0, 4);
    }
};

class TTetromino : public Tetromino
{
public:
    TTetromino()
    {
        id = 3;
        rotations[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        rotations[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        rotations[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        rotations[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        setInitialPosition(0, 3);
    }
};

class LTetromino : public Tetromino
{
public:
    LTetromino()
    {
        id = 4;
        rotations[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
        rotations[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
        rotations[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
        rotations[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
        setInitialPosition(0, 3);
    }
};

class JTetromino : public Tetromino
{
public:
    JTetromino()
    {
        id = 5;
        rotations[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
        rotations[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        rotations[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        rotations[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
        setInitialPosition(0, 3);
    }
};

class STetromino : public Tetromino
{
public:
    STetromino()
    {
        id = 6;
        rotations[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        rotations[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
        rotations[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
        rotations[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
        setInitialPosition(0, 3);
    }
};

class ZTetromino : public Tetromino
{
public:
    ZTetromino()
    {
        id = 7;
        rotations[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        rotations[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        rotations[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
        rotations[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
        setInitialPosition(0, 3);
    }
};