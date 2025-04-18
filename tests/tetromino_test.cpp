#include <gtest/gtest.h>
#include <vector>
#include "../src/tetrominoes.cpp"
#include "../include/position.h"

class TetrominoTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        iTetromino = ITetromino();
        oTetromino = OTetromino();
        tTetromino = TTetromino();
        lTetromino = LTetromino();
        jTetromino = JTetromino();
        sTetromino = STetromino();
        zTetromino = ZTetromino();
    }

    ITetromino iTetromino;
    OTetromino oTetromino;
    TTetromino tTetromino;
    LTetromino lTetromino;
    JTetromino jTetromino;
    STetromino sTetromino;
    ZTetromino zTetromino;
};

TEST_F(TetrominoTest, Initialize)
{
    EXPECT_EQ(iTetromino.id, 1);
    EXPECT_EQ(oTetromino.id, 2);
    EXPECT_EQ(tTetromino.id, 3);
    EXPECT_EQ(lTetromino.id, 4);
    EXPECT_EQ(jTetromino.id, 5);
    EXPECT_EQ(sTetromino.id, 6);
    EXPECT_EQ(zTetromino.id, 7);
}

TEST_F(TetrominoTest, GetCellPositions)
{
    vector<Position> positions = oTetromino.getCellPositions();
    vector<Position> expected = {Position(0, 4), Position(0, 5), Position(1, 4), Position(1, 5)};

    ASSERT_EQ(positions.size(), expected.size());

    for (size_t i = 0; i < positions.size(); i++)
    {
        EXPECT_EQ(positions[i].row, expected[i].row);
        EXPECT_EQ(positions[i].col, expected[i].col);
    }
}

TEST_F(TetrominoTest, Move)
{
    vector<Position> initialPositions = iTetromino.getCellPositions();

    int rowShift = 8;
    int colShift = 23;
    iTetromino.move(rowShift, colShift);

    vector<Position> movedPositions = iTetromino.getCellPositions();

    ASSERT_EQ(initialPositions.size(), movedPositions.size());

    for (size_t i = 0; i < initialPositions.size(); i++)
    {
        EXPECT_EQ(movedPositions[i].row, initialPositions[i].row + rowShift);
        EXPECT_EQ(movedPositions[i].col, initialPositions[i].col + colShift);
    }
}

TEST_F(TetrominoTest, RotateRight)
{
    vector<Position> expected = {Position(0, 4), Position(1, 4), Position(1, 5), Position(2, 4)};

    int prevRotateState = tTetromino.rotateRight();

    vector<Position> rotatedPositions = tTetromino.getCellPositions();

    ASSERT_EQ(prevRotateState, 0);
    ASSERT_EQ(expected.size(), rotatedPositions.size());
    for (size_t i = 0; i < rotatedPositions.size(); i++)
    {
        EXPECT_EQ(expected[i].row, rotatedPositions[i].row);
        EXPECT_EQ(expected[i].col, rotatedPositions[i].col);
    }
}

TEST_F(TetrominoTest, RotateLeft)
{
    vector<Position> expected = {Position(0, 3), Position(0, 4), Position(1, 4), Position(2, 4)};

    int prevRotateState = lTetromino.rotateLeft();

    vector<Position> rotatedPositions = lTetromino.getCellPositions();

    ASSERT_EQ(prevRotateState, 0);
    ASSERT_EQ(expected.size(), rotatedPositions.size());
    for (size_t i = 0; i < rotatedPositions.size(); i++)
    {
        EXPECT_EQ(expected[i].row, rotatedPositions[i].row);
        EXPECT_EQ(expected[i].col, rotatedPositions[i].col);
    }
}