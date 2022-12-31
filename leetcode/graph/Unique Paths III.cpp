// You are given an m x n integer array grid where grid[i][j] could be:

// 1 representing the starting square. There is exactly one starting square.
// 2 representing the ending square. There is exactly one ending square.
// 0 representing empty squares we can walk over.
// -1 representing obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

// Example 1:

// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// Output: 2
// Explanation: We have the following two paths:
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
// Example 2:

// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// Output: 4
// Explanation: We have the following four paths:
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
// Example 3:

// Input: grid = [[0,1],[2,0]]
// Output: 0
// Explanation: There is no path that walks over every empty square exactly once.
// Note that the starting and ending square can be anywhere in the grid.

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 20
// 1 <= m * n <= 20
// -1 <= grid[i][j] <= 2
// There is exactly one starting cell and one ending cell.

class Solution
{
    int ans = 0;
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

private:
    // checks if cell is valid. If none of 3 points mentioned in post is satisfied, it is a valid cell
    bool isValid(int row, int col, vector<vector<int>> &grid)
    {
        return row >= 0 and row < size(grid) and col >= 0 and col < size(grid[0]) and grid[row][col] != -1 and grid[row][col] != 3;
    }
    void dfs(int row, int col, vector<vector<int>> &grid, int cellsToVisit)
    {
        if (!isValid(row, col, grid))
            return;
        if (grid[row][col] == 2)
        {
            if (cellsToVisit == 0)
                ans++;
            return;
        }
        grid[row][col] = 3;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            dfs(nrow, ncol, grid, cellsToVisit - 1);
        }
        grid[row][col] = 0;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int srow, scol, cellsToVisit = 0; // sr=starting row,scol=starting col,cellsToVisit=number of cells to be visited  in the grid
        for (int i = 0; i < size(grid); i++)
        {
            for (int j = 0; j < size(grid[0]); j++)
            {
                if (grid[i][j] == 1)
                {
                    srow = i, scol = j;
                }
                else if (grid[i][j] != -1)
                { // we will also consider the end grid
                    cellsToVisit++;
                }
            }
        }

        dfs(srow, scol, grid, cellsToVisit);
        return ans;
    }
};