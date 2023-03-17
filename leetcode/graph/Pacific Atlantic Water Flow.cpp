// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

// Example 1:

// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
// [0,4]: [0,4] -> Pacific Ocean
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
// Example 2:

// Input: heights = [[1]]
// Output: [[0,0]]
// Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

// Constraints:

// m == heights.length
// n == heights[r].length
// 1 <= m, n <= 200
// 0 <= heights[r][c] <= 105

class Solution
{
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    void dfs(vector<vector<int>> &heights, int row, int col, vector<vector<bool>> &ocean, int n, int m)
    {
        ocean[row][col] = true;
        for (int i = 0; i < 4; i++)
        {
            int nrow = dr[i] + row;
            int ncol = dc[i] + col;

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !ocean[nrow][ncol] && heights[nrow][ncol] >= heights[row][col])
            {
                dfs(heights, nrow, ncol, ocean, n, m);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> ans;
        int rows = heights.size(), cols = heights[0].size();

        // vector to mark all the cells that can flow into Pacific and Atlantic oceans separately
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // call the dfs function for cells in the first and last column to mark cells that can flow into Pacific and Atlantic oceans
        for (int i = 0; i < rows; i++)
        {
            dfs(heights, i, 0, pacific, rows, cols);         // explore cells in the first column
            dfs(heights, i, cols - 1, atlantic, rows, cols); // explore cells in the last column
        }

        // call the dfs function for cells in the first and last row to mark cells that can flow into Pacific and Atlantic oceans
        for (int i = 0; i < cols; i++)
        {
            dfs(heights, 0, i, pacific, rows, cols);         // explore cells in the first row
            dfs(heights, rows - 1, i, atlantic, rows, cols); // explore cells in the last row
        }

        // check all cells to see if they can flow into both Pacific and Atlantic oceans
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (pacific[i][j] and atlantic[i][j]) // if the cell can flow into both oceans
                    ans.push_back({i, j});            // add it to the answer vector
            }
        }
        return ans; // return the answer
    }
};
