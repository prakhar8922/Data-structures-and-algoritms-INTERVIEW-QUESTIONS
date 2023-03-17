// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

// Example 1:

// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
// Example 2:

// Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size(), dist = 0;
        vector<vector<int>> temp = grid;

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        queue<pair<int, int>> q; //{row,col}

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[i][j] == 1)
                    q.push({i, j});
            }
        }
        if (q.empty() or q.size() == n * n)
            return -1; // If the queue q is either empty or has the same size as the total number of cells in the grid, this means that either there is no land or all cells are land. In either case, the function returns -1.
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];
                    if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < n and temp[nrow][ncol] == 0)
                    {
                        temp[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            dist++;
        }
        return dist - 1; // The final value of dist will include the step taken to reach the land cell itself, so we need to subtract 1 from dist to get the distance to the nearest land cell. Hence, dist-1 is returned instead of dist itself.
    }
};