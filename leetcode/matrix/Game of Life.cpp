// 289. Game of Life
// Medium
// 5.6K
// 478
// Companies
// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

// Example 1:

// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
// Example 2:

// Input: board = [[1,1],[1,0]]
// Output: [[1,1],[1,1]]

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 25
// board[i][j] is 0 or 1.

// Follow up:

// Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
// In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

class Solution
{
public:
    int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int countneighbour1(int row, int col, vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int count1 = 0;
        for (int i = 0; i < 8; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow >= 0 and ncol >= 0 and nrow < m and ncol < n and grid[nrow][ncol] == 1)
                count1++;
        }
        return count1;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> grid = board;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int count1 = countneighbour1(i, j, grid);
                    if (count1 < 2)
                        board[i][j] = 0;
                    else if (count1 == 2 or count1 == 3)
                        board[i][j] = 1;
                    else if (count1 > 3)
                        board[i][j] = 0;
                }
                else
                {
                    int count1 = countneighbour1(i, j, grid);
                    if (count1 == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
};
// space complexity-O(MN)

class Solution
{
public:
    int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int countneighbour1(int row, int col, vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int count1 = 0;
        for (int i = 0; i < 8; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow >= 0 and ncol >= 0 and nrow < m and ncol < n and (grid[nrow][ncol] == 1 or grid[nrow][ncol] == 3))
                count1++;
        }
        return count1;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        // vector<vector<int>>grid=board;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count1 = countneighbour1(i, j, board);
                if (board[i][j] == 1)
                {
                    if (count1 < 2 or count1 > 3)
                        board[i][j] = 3; // newly dead
                }
                else
                { // currently dead
                    // can become alive if has exactly three live neighbours

                    if (count1 == 3)
                        board[i][j] = 2; // newly alive
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 3)
                    board[i][j] = 0;
                if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};

// space complexity( O(1))