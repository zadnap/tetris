#include <gtest/gtest.h>
#include "../include/game.h"

class GameIntegrationTest : public ::testing::Test
{
protected:
    Game game;

    void SetUp() override
    {
        game.startNew();
    }

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

TEST_F(GameIntegrationTest, StartNew)
{
    EXPECT_EQ(game.getState(), GameState::Playing);
    EXPECT_EQ(game.getScore(), 0);
    EXPECT_EQ(game.getLevel(), 0);
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

TEST_F(GameIntegrationTest, HardDropTetromino)
{
    Tetromino currentTetromino = game.getCurrentTetromino();
    vector<Position> initCellPositions = currentTetromino.getCellPositions();

    int distance = game.getBoard().getNumRows() - getDownMostRow() - 1;

    game.hardDropTetromino();

    for (Position cellPos : initCellPositions)
    {
        EXPECT_EQ(game.getBoard().getCell(cellPos.row + distance, cellPos.col), currentTetromino.id);
    }
}

TEST_F(GameIntegrationTest, UpdateScoreAfterClearingRows)
{
    Board &board = game.getBoard();
    int numCols = board.getNumCols();
    int numRows = board.getNumRows();

    for (int i = 0; i < numCols; i++)
        board.setCell(numRows - 1, i, 1);

    game.hardDropTetromino();

    EXPECT_EQ(game.getScore(), 100);
}

TEST_F(GameIntegrationTest, IncreaseLevelAfterTenRowsCleared)
{
    Board &board = game.getBoard();
    int numCols = board.getNumCols();
    int numRows = board.getNumRows();

    int times = 3;
    while (times > 0)
    {
        for (int i = 16; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                board.setCell(i, j, 1);
            }
        }

        game.hardDropTetromino();
        times--;
    }

    EXPECT_EQ(game.getLevel(), 1);
}

TEST_F(GameIntegrationTest, DetectGameOver)
{
    Board &board = game.getBoard();
    int numRows = board.getNumRows();
    int numCols = board.getNumCols();

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
            board.setCell(i, j, 1);
    }

    game.hardDropTetromino();

    EXPECT_EQ(game.getState(), GameState::GameOver);
}
