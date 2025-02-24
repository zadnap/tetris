#pragma once
#include <vector>
using namespace std;

class Grid
{
private:
    int numRows;
    int numCols;
    vector<vector<int>> grid;
    bool isCompleteRow(int row) const;
    void clearRow(int row);
    void moveRowsDown(int row, int distance);

public:
    Grid(int numRows = 20, int numCols = 10);
    void clearGrid();
    bool isWithinBounds(int row, int col) const;
    int getCell(int row, int col) const;
    void setCell(int row, int col, int value);
    bool canPlace(int row, int col) const;
    int clearCompleteRows();
    bool isFull() const;
};