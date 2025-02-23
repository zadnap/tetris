#include "../include/grid.h"
#include <vector>
#include <stdexcept>
using namespace std;

Grid::Grid(int rows, int cols)
{
    numRows = rows;
    numCols = cols;
    clearGrid();
}

void Grid::clearGrid()
{
    grid = vector<vector<int>>(numRows, vector<int>(numCols, 0));
}

bool Grid::isWithinBounds(int row, int col) const
{
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}

int Grid::getCell(int row, int col) const
{
    if (!isWithinBounds(row, col))
        throw out_of_range("You are touching outside the grid!");
    return grid[row][col];
}

void Grid::setCell(int row, int col, int value)
{
    if (!isWithinBounds(row, col))
        throw out_of_range("You are touching outside the grid!");
    if (value < 0 || value > 7)
        throw invalid_argument("The value should be from 0 to 7!");
    grid[row][col] = value;
}

bool Grid::canPlace(int row, int col) const
{
    if (!isWithinBounds(row, col))
        throw out_of_range("You are touching outside the grid!");
    return grid[row][col] == 0;
}

int Grid::clearCompleteRows()
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
bool Grid::isCompleteRow(int row) const
{
    for (int col = 0; col < numCols; col++)
        if (getCell(row, col) == 0)
            return false;
    return true;
}
void Grid::clearRow(int row)
{
    for (int col = 0; col < numCols; col++)
        setCell(row, col, 0);
}
void Grid::moveRowsDown(int row, int distance)
{
    if (row + distance >= numRows)
        return;

    for (int column = 0; column < numCols; column++)
    {
        grid[row + distance][column] = grid[row][column];
        grid[row][column] = 0;
    }
}

bool Grid::isFull() const
{
    for (int col = 0; col < numCols; col++)
    {
        if (grid[0][col] != 0)
            return true;
    }
    return false;
}