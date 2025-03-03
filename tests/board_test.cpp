#include <gtest/gtest.h>
#include "../include/board.h"

class BoardTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        defaultNumRows = 20;
        defaultNumCols = 10;
        board = Board();
    }

    int defaultNumRows, defaultNumCols;
    Board board;
};

TEST_F(BoardTest, Initialize)
{
    ASSERT_EQ(board.getNumRows(), defaultNumRows);
    ASSERT_EQ(board.getNumCols(), defaultNumCols);

    for (int i = 0; i < defaultNumRows; i++)
    {
        for (int j = 0; j < defaultNumCols; j++)
        {
            EXPECT_EQ(board.getCell(i, j), 0);
        }
    }
}

TEST_F(BoardTest, InitializeWithSpecificSize)
{
    int specificRows = 23;
    int specificCols = 8;

    board = Board(specificRows, specificCols);

    ASSERT_EQ(board.getNumRows(), specificRows);
    ASSERT_EQ(board.getNumCols(), specificCols);
}

TEST_F(BoardTest, IsWithinBounds)
{
    EXPECT_FALSE(board.isWithinBounds(-1, 0));
    EXPECT_FALSE(board.isWithinBounds(defaultNumRows, defaultNumCols));
    EXPECT_FALSE(board.isWithinBounds(999, -999));
}

TEST_F(BoardTest, SetCell)
{
    board.setCell(0, 0, 1);
    board.setCell(0, 1, 2);
    board.setCell(0, 3, 6);

    EXPECT_EQ(board.getCell(0, 0), 1);
    EXPECT_EQ(board.getCell(0, 1), 2);
    EXPECT_EQ(board.getCell(0, 3), 6);
}

TEST_F(BoardTest, SetCellWithInvalidValue)
{
    EXPECT_THROW(board.setCell(0, 0, -1), invalid_argument);
    EXPECT_THROW(board.setCell(0, 0, 8), invalid_argument);
    EXPECT_THROW(board.setCell(0, 0, 23), invalid_argument);
}

TEST_F(BoardTest, CanPlace)
{
    EXPECT_TRUE(board.canPlace(0, 0));

    board.setCell(0, 0, 1);

    EXPECT_FALSE(board.canPlace(0, 0));
}

TEST_F(BoardTest, TouchOutSide)
{
    EXPECT_THROW(board.getCell(-1, -1), out_of_range);
    EXPECT_THROW(board.setCell(999, 999, 7), out_of_range);
    EXPECT_FALSE(board.canPlace(999, 999));
}

TEST_F(BoardTest, ClearCompleteRow)
{
    board.setCell(defaultNumRows - 1, 0, 1);
    board.setCell(defaultNumRows - 1, 4, 1);

    for (int col = 0; col < defaultNumCols; col++)
        board.setCell(defaultNumRows - 2, col, 2);

    board.setCell(defaultNumRows - 3, 0, 3);
    board.setCell(defaultNumRows - 3, 5, 3);

    for (int col = 0; col < defaultNumCols; col++)
        board.setCell(defaultNumRows - 4, col, 4);

    int rowsCleared = board.clearCompleteRows();

    EXPECT_EQ(rowsCleared, 2);
    EXPECT_EQ(board.getCell(defaultNumRows - 1, 0), 1);
    EXPECT_EQ(board.getCell(defaultNumRows - 1, 4), 1);
    EXPECT_EQ(board.getCell(defaultNumRows - 2, 5), 3);
    EXPECT_EQ(board.getCell(defaultNumRows - 2, 5), 3);
}

TEST_F(BoardTest, IsFull)
{
    EXPECT_FALSE(board.isFull());

    board.setCell(0, 0, 1);

    EXPECT_TRUE(board.isFull());
}