#include <gtest/gtest.h>
#include "../include/grid.h"

class GridTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        defaultNumRows = 20;
        defaultNumCols = 10;
        grid = Grid();
    }

    int defaultNumRows, defaultNumCols;
    Grid grid;
};

TEST_F(GridTest, Initialization)
{
    for (int i = 0; i < defaultNumRows; i++)
    {
        for (int j = 0; j < defaultNumCols; j++)
        {
            EXPECT_EQ(grid.getCell(i, j), 0);
        }
    }
}

TEST_F(GridTest, IsWithinBounds)
{
    EXPECT_FALSE(grid.isWithinBounds(-1, 0));
    EXPECT_FALSE(grid.isWithinBounds(defaultNumRows, defaultNumCols));
    EXPECT_FALSE(grid.isWithinBounds(999, -999));
}

TEST_F(GridTest, SetCell)
{
    grid.setCell(0, 0, 1);
    grid.setCell(0, 1, 2);
    grid.setCell(0, 3, 6);

    EXPECT_EQ(grid.getCell(0, 0), 1);
    EXPECT_EQ(grid.getCell(0, 1), 2);
    EXPECT_EQ(grid.getCell(0, 3), 6);
}

TEST_F(GridTest, SetCellWithInvalidValue)
{
    EXPECT_THROW(grid.setCell(0, 0, -1), invalid_argument);
    EXPECT_THROW(grid.setCell(0, 0, 8), invalid_argument);
    EXPECT_THROW(grid.setCell(0, 0, 23), invalid_argument);
}

TEST_F(GridTest, CanPlace)
{
    EXPECT_TRUE(grid.canPlace(0, 0));

    grid.setCell(0, 0, 1);

    EXPECT_FALSE(grid.canPlace(0, 0));
}

TEST_F(GridTest, TouchOutSide)
{
    EXPECT_THROW(grid.getCell(-1, -1), out_of_range);
    EXPECT_THROW(grid.setCell(999, 999, 7), out_of_range);
    EXPECT_THROW(grid.canPlace(999, 999), out_of_range);
}

TEST_F(GridTest, ClearCompleteRow)
{
    grid.setCell(defaultNumRows - 1, 0, 1);
    grid.setCell(defaultNumRows - 1, 4, 1);

    for (int col = 0; col < defaultNumCols; col++)
        grid.setCell(defaultNumRows - 2, col, 2);

    grid.setCell(defaultNumRows - 3, 0, 3);
    grid.setCell(defaultNumRows - 3, 5, 3);

    for (int col = 0; col < defaultNumCols; col++)
        grid.setCell(defaultNumRows - 4, col, 4);

    int rowsCleared = grid.clearCompleteRows();

    EXPECT_EQ(rowsCleared, 2);
    EXPECT_EQ(grid.getCell(defaultNumRows - 1, 0), 1);
    EXPECT_EQ(grid.getCell(defaultNumRows - 1, 4), 1);
    EXPECT_EQ(grid.getCell(defaultNumRows - 2, 5), 3);
    EXPECT_EQ(grid.getCell(defaultNumRows - 2, 5), 3);
}

TEST_F(GridTest, IsFull)
{
    EXPECT_FALSE(grid.isFull());

    grid.setCell(0, 0, 1);

    EXPECT_TRUE(grid.isFull());
}