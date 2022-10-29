// You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// Example 1:

// Input:
// grid[][] = {{0, 0, 0, 0},
//             {1, 0, 1, 0},
//             {0, 1, 1, 0},
//             {0, 0, 0, 0}}
// Output:
// 3
// Explanation:
// 0 0 0 0
// 1 0 1 0
// 0 1 1 0
// 0 0 0 0
// The highlighted cells represents the land cells.
// Example 2:

// Input:
// grid[][] = {{0, 0, 0, 1},
//             {0, 1, 1, 0},
//             {0, 1, 1, 0},
//             {0, 0, 0, 1},
//             {0, 1, 1, 0}}
// Output:
// 4
// Explanation:
// 0 0 0 1
// 0 1 1 0
// 0 1 1 0
// 0 0 0 1
// 0 1 1 0
// The highlighted cells represents the land cells.
// Your Task:

// You don't need to print or input anything. Complete the function numberOfEnclaves() which takes a 2D integer matrix grid as the input parameter and returns an integer, denoting the number of land cells.

// Expected Time Complexity: O(n * m)

// Expected Space Complexity: O(n * m)

// Constraints:

// 1 <= n, m <= 500
// grid[i][j] == 0 or 1

class Solution
{
public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        // Code here
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m] = {0};
        // traverse boundary elements
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // first row, first col, last row, last col
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    // if it is a land then store it in queue
                    if (grid[i][j] == 1)
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverses all 4 directions
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                // check for valid coordinates and for land cell
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // check for unvisited land cell
                if (grid[i][j] == 1 & vis[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};

// class Solution {
//   public:
//     void dfs(int i, int j, vector<vector<int>> &grid) {
//         if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or
//             grid[i][j] == 0) {
//             return;
//         }

//         grid[i][j] = 0;
//         dfs(i + 1, j, grid);
//         dfs(i, j + 1, grid);
//         dfs(i, j - 1, grid);
//         dfs(i - 1, j, grid);
//     }

//     int numberOfEnclaves(vector<vector<int>> &grid) {

//         int n = grid.size();
//         int m = grid[0].size();

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (i == 0 or j == 0 or i == n - 1 or
//                     j == m - 1 and grid[i][j] == 1) {
//                     dfs(i, j, grid);
//                 }
//             }
//         }

//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 count += grid[i][j];
//             }
//         }

//         return count;
//     }
// };