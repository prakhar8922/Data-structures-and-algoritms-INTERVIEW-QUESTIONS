// 934. Shortest Bridge
// Medium
// 4.2K
// 164
// Companies
// You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

// An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

// You may change 0's to 1's to connect the two islands to form one island.

// Return the smallest number of 0's you must flip to connect the two islands.

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 1
// Example 2:

// Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2
// Example 3:

// Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1

// Constraints:

// n == grid.length == grid[i].length
// 2 <= n <= 100
// grid[i][j] is either 0 or 1.
// There are exactly two islands in grid.
// Accepted
// 147.1K
// Submissions
// 262K
// Acceptance Rate
// 56.1%

class Solution
{
public:
    //   Time Complexity - O(k * r * c)
    //  Space Complexity -  O(r * c)
    //   k is the number of cells representing the starting island
    //    r is the number of row
    //   c is the number of column

    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    // Function to check if a cell is within the boundaries of the grid
    bool isValid(int i, int j, int r, int c)
    {
        return (i < r && j < c && i >= 0 && j >= 0);
    }

    // Function to change the island type using DFS
    void changeIslandType(int i, int j, int r, int c, vector<vector<int>> &grid)
    {
        if (i >= r || j >= c || i < 0 || j < 0 || grid[i][j] == 0 || grid[i][j] == 2)
            return;

        // Change the island type to 2 (visited)
        grid[i][j] = 2;

        // Explore the neighboring cells in the four cardinal directions
        for (int x = 0; x < 4; ++x)
        {
            int nr = i + dx[x];
            int nc = j + dy[x];

            // Recursively call the function for valid neighboring cells
            changeIslandType(nr, nc, r, c, grid);
        }
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;

        int change = 0;
        bool check = false;

        // Find the first island and change its type to 2 (visited)
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j])
                {
                    changeIslandType(i, j, r, c, grid);
                    check = true;
                    break;
                }
            }
            if (check)
                break;
        }

        // Add the cells of the new islands (type 2) to the queue
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            change++;
            int sz = q.size();

            while (sz--)
            {
                auto node = q.front();
                q.pop();

                // Explore the neighboring cells in the four cardinal directions
                for (int x = 0; x < 4; ++x)
                {
                    int nr = node.first + dx[x];
                    int nc = node.second + dy[x];

                    // Check if the neighboring cell is valid
                    if (isValid(nr, nc, r, c))
                    {
                        // If the neighboring cell is a water cell (0), change its type to 2 and add it to the queue
                        if (grid[nr][nc] == 0)
                        {
                            grid[nr][nc] = 2;
                            q.push({nr, nc});
                        }

                        // If the neighboring cell is the second island (type 1), return the shortest distance (change-1)
                        if (grid[nr][nc] == 1)
                            return change - 1;
                    }
                }
            }
        }

        // If no second island is found, return 0
        return 0;
    }
};