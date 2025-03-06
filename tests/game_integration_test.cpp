#include <gtest/gtest.h>
#include "../include/game.h"

class GameIntegrationTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        game = Game();
    }

    Game game;

    int getLeftMostCol()
    {
        vector<Position> cellPositions = game.getCurrentTetromino().getCellPositions();
        int leftMostCol = cellPositions[0].col;
        for (Position cellPos : cellPositions)
        {
            if (cellPos.col < leftMostCol)
                leftMostCol = cellPos.col;
        }
        return leftMostCol;
    }

    int getRightMostCol()
    {
        vector<Position> cellPositions = game.getCurrentTetromino().getCellPositions();
        int rightMostCol = cellPositions[0].col;
        for (Position cellPos : cellPositions)
        {
            if (cellPos.col > rightMostCol)
                rightMostCol = cellPos.col;
        }
        return rightMostCol;
    }

    int getDownMostRow()
    {
        vector<Position> cellPositions = game.getCurrentTetromino().getCellPositions();
        int downMostRow = cellPositions[0].row;
        for (Position cellPos : cellPositions)
        {
            if (cellPos.row > downMostRow)
                downMostRow = cellPos.row;
        }
        return downMostRow;
    }
};

TEST_F(GameIntegrationTest, Initialize)
{
    EXPECT_FALSE(game.isGameOver());
    EXPECT_EQ(game.getScore(), 0);
    EXPECT_GE(game.getCurrentTetromino().id, 0);
    EXPECT_LE(game.getCurrentTetromino().id, 7);
    EXPECT_GE(game.getNextTetromino().id, 0);
    EXPECT_LE(game.getNextTetromino().id, 7);
}

TEST_F(GameIntegrationTest, StopTetrominoAtLeftEdge)
{
    int steps = getLeftMostCol();

    while (steps >= 0)
    {
        game.moveTetrominoLeft();
        steps--;
    }

    EXPECT_EQ(getLeftMostCol(), 0);
}

TEST_F(GameIntegrationTest, StopTetrominoAtRightEdge)
{
    int lastCol = game.getBoard().getNumCols() - 1;
    int steps = lastCol - getRightMostCol();

    while (steps >= 0)
    {
        game.moveTetrominoRight();
        steps--;
    }

    EXPECT_EQ(getRightMostCol(), lastCol);
}

TEST_F(GameIntegrationTest, StopTetrominoAtBottomEdge)
{
    int lastRow = game.getBoard().getNumRows() - 1;
    int steps = lastRow - getDownMostRow();

    while (steps >= 0)
    {
        game.moveTetrominoDown();
        steps--;
    }

    EXPECT_EQ(getDownMostRow(), lastRow);
}

TEST_F(GameIntegrationTest, DetectCollisionAtBottom)
{
    int lastRow = game.getBoard().getNumRows() - 1;

    for (int i = 0; i < game.getBoard().getNumCols(); i++)
        game.getBoard().setCell(lastRow, i, 1);

    int steps = lastRow - getDownMostRow();

    while (steps >= 0)
    {
        game.moveTetrominoDown();
        steps--;
    }

    EXPECT_EQ(getDownMostRow(), lastRow - 1);
}

TEST_F(GameIntegrationTest, DetectCollisionOnLeft)
{
    game.getBoard().setCell(0, 0, 1);
    game.getBoard().setCell(1, 0, 1);
    game.getBoard().setCell(2, 0, 1);
    game.getBoard().setCell(3, 0, 1);

    int steps = getLeftMostCol();

    while (steps >= 0)
    {
        game.moveTetrominoLeft();
        steps--;
    }

    EXPECT_EQ(getLeftMostCol(), 1);
}

TEST_F(GameIntegrationTest, DetectCollisionOnRight)
{
    int lastCol = game.getBoard().getNumCols() - 1;
    game.getBoard().setCell(0, lastCol, 1);
    game.getBoard().setCell(1, lastCol, 1);
    game.getBoard().setCell(2, lastCol, 1);
    game.getBoard().setCell(3, lastCol, 1);

    int steps = lastCol - getRightMostCol();

    while (steps >= 0)
    {
        game.moveTetrominoRight();
        steps--;
    }

    EXPECT_EQ(getRightMostCol(), lastCol - 1);
}

TEST_F(GameIntegrationTest, RotateOnLeftEdge)
{
    game.rotateTetrominoRight();
    int steps = getLeftMostCol();

    while (steps >= 0)
    {
        game.moveTetrominoLeft();
        steps--;
    }
    game.rotateTetrominoLeft();

    EXPECT_GE(getLeftMostCol(), 0);
}

TEST_F(GameIntegrationTest, RotateOnRightEdge)
{
    int numCols = game.getBoard().getNumCols();
    game.rotateTetrominoLeft();
    int steps = numCols - getRightMostCol();

    while (steps >= 0)
    {
        game.moveTetrominoRight();
        steps--;
    }
    game.rotateTetrominoRight();

    EXPECT_LE(getRightMostCol(), numCols - 1);
}

TEST_F(GameIntegrationTest, RotateOnBottomEdge)
{
    int numRows = game.getBoard().getNumRows();
    int steps = numRows - getDownMostRow();

    while (steps >= 0)
    {
        game.moveTetrominoDown();
        steps--;
    }
    game.rotateTetrominoRight();

    EXPECT_LE(getDownMostRow(), numRows - 1);
}

TEST_F(GameIntegrationTest, DetectCollisionOnRotatingLeft)
{
    game.getBoard().setCell(0, 0, 1);
    game.getBoard().setCell(1, 0, 1);
    game.getBoard().setCell(2, 0, 1);
    game.getBoard().setCell(3, 0, 1);

    game.rotateTetrominoRight();
    int steps = getLeftMostCol();

    while (steps >= 0)
    {
        game.moveTetrominoDown();
        steps--;
    }
    game.rotateTetrominoLeft();

    EXPECT_GE(getLeftMostCol(), 1);
}

TEST_F(GameIntegrationTest, DetectCollisionOnRotatingRight)
{
    int lastCol = game.getBoard().getNumCols() - 1;

    game.getBoard().setCell(0, lastCol, 1);
    game.getBoard().setCell(1, lastCol, 1);
    game.getBoard().setCell(2, lastCol, 1);
    game.getBoard().setCell(3, lastCol, 1);

    game.rotateTetrominoLeft();
    int steps = lastCol - getRightMostCol();

    while (steps >= 0)
    {
        game.moveTetrominoRight();
        steps--;
    }
    game.rotateTetrominoRight();

    EXPECT_LE(getRightMostCol(), lastCol - 1);
}