// 1254. Number of Closed Islands
// Medium
// 4K
// 137
// Companies
// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

// Return the number of closed islands.

// Example 1:

// Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation:
// Islands in gray are closed because they are completely surrounded by water (group of 1s).
// Example 2:

// Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// Output: 1
// Example 3:

// Input: grid = [[1,1,1,1,1,1,1],
//                [1,0,0,0,0,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,1,0,1,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,0,0,0,0,1],
//                [1,1,1,1,1,1,1]]
// Output: 2

// Constraints:

// 1 <= grid.length, grid[0].length <= 100
// 0 <= grid[i][j] <=1
// Accepted
// 183.7K
// Submissions
// 273.9K
// Acceptance Rate
// 67.1%

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &grid)
    {
        // The DFS function takes the row, column, and the grid as input
        int m = grid.size(), n = grid[0].size();
        // m and n are the dimensions of the grid
        if (row < 0 or row >= m or col < 0 or col >= n or grid[row][col] != 0)
            return;
        // If the current cell is out of bounds or not a 0, return
        grid[row][col] = 1;
        // Mark the current cell as visited by changing its value to 1
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        // dr and dc define the four possible directions to move in the grid
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            // Get the new row and column indices by moving in the current direction
            dfs(nrow, ncol, grid);
            // Recursively call the DFS function on the new cell
        }
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        // m and n are the dimensions of the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 or j == 0 or i == m - 1 or j == n - 1) and grid[i][j] == 0)
                {
                    // If the current cell is on the border and is a 0, call the DFS function
                    dfs(i, j, grid);
                }
            }
        }
        int ans = 0;
        // Initialize the answer to 0
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    // If the current cell is a 0, it is part of a closed island
                    dfs(i, j, grid);
                    // Call the DFS function to mark all the cells that belong to this island
                    ans++;
                    // Increment the answer by 1
                }
            }
        }
        return ans;
        // Return the answer
    }
};