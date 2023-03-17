// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

// Example 1:

// Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output: 24
// Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
// Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
// Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
// Total of cherries: 12 + 12 = 24.
// Example 2:

// Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
// Output: 28
// Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
// Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
// Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
// Total of cherries: 17 + 11 = 28.

// Constraints:

// rows == grid.length
// cols == grid[i].length
// 2 <= rows, cols <= 70
// 0 <= grid[i][j] <= 100

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        // base cases
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                    dp[n - 1][i][j] = grid[n - 1][i]; // if both robots are at same cell only add it once in dp
                else
                    dp[n - 1][i][j] = grid[n - 1][i] + grid[n - 1][j]; // if they are at different then we add both of them to dp
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int mx = -1e9;
                    for (int dr = -1; dr <= 1; dr++)
                    { // here dr is the possible cells robot 1 can move
                        for (int dc = -1; dc <= 1; dc++)
                        { // dc is the possible cells robot 2 can move for each cell of robot1
                            int val = 0;
                            if (j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            if (j1 + dr < 0 or j1 + dr >= m or j2 + dc < 0 or j2 + dc >= m)
                                val += -1e9;
                            else
                                val += dp[i + 1][j1 + dr][j2 + dc];
                            mx = max(mx, val);
                        }
                    }
                    dp[i][j1][j2] = mx;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};