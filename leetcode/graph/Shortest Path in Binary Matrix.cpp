// 1091. Shortest Path in Binary Matrix
// Medium
// 5K
// 192
// Companies
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 2
// Example 2:

// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1
// Accepted
// 323K
// Submissions
// 711.4K
// Acceptance Rate
// 45.4%

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }
        queue<vector<int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;
        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int row = cell[0];
            int col = cell[1];
            int dis = cell[2];
            if (row == n - 1 and col == n - 1)
                return dis;
            for (int i = 0; i < 8; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < n and grid[nrow][ncol] == 0)
                {
                    grid[nrow][ncol] = 1;
                    q.push({nrow, ncol, dis + 1});
                }
            }
        }

        return -1;
    }
};