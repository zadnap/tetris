#include "../include/board.h"
#include <vector>
#include <stdexcept>
using namespace std;

Board::Board(int numRows, int numCols)
{
    this->numRows = numRows;
    this->numCols = numCols;
    clearBoard();
}

void Board::clearBoard()
{
    grid = vector<vector<int>>(numRows, vector<int>(numCols, 0));
}

bool Board::isWithinBounds(int row, int col) const
{
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}

int Board::getCell(int row, int col) const
{
    if (!isWithinBounds(row, col))
        throw out_of_range("You are touching outside the grid!");
    return grid[row][col];
}

void Board::setCell(int row, int col, int value)
{
    if (!isWithinBounds(row, col))
        throw out_of_range("You are touching outside the grid!");
    if (value < 0 || value > 7)
        throw invalid_argument("The value should be from 0 to 7!");
    grid[row][col] = value;
}

bool Board::canPlace(int row, int col) const
{
    if (!isWithinBounds(row, col))
        throw out_of_range("You are touching outside the grid!");
    return grid[row][col] == 0;
}

int Board::clearCompleteRows()
{
    int rowsCleared = 0;

    for (int row = numRows - 1; row >= 0; row--)
    {
        if (isCompleteRow(row))
        {
            clearRow(row);
            rowsCleared++;
        }
        else if (rowsCleared > 0)
        {
            moveRowsDown(row, rowsCleared);
        }
    }

    return rowsCleared;
}
bool Board::isCompleteRow(int row) const
{
    for (int col = 0; col < numCols; col++)
        if (grid[row][col] == 0)
            return false;
    return true;
}
void Board::clearRow(int row)
{
    for (int col = 0; col < numCols; col++)
        setCell(row, col, 0);
}
void Board::moveRowsDown(int row, int distance)
{
    if (row + distance >= numRows)
        return;

    for (int column = 0; column < numCols; column++)
    {
        grid[row + distance][column] = grid[row][column];
        grid[row][column] = 0;
    }
}

bool Board::isFull() const
{
    for (int col = 0; col < numCols; col++)
    {
        if (grid[0][col] != 0)
            return true;
    }
    return false;
}