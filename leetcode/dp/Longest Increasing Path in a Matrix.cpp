// 329. Longest Increasing Path in a Matrix
// Hard
// 7.8K
// 116
// Companies
// Given an m x n integers matrix, return the length of the longest increasing path in matrix.

// From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

// Example 1:

// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].
// Example 2:

// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
// Example 3:

// Input: matrix = [[1]]
// Output: 1

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 231 - 1

class Solution
{
public:
    int dp[201][201];
    int dfs(vector<vector<int>> &mat, int i, int j, int pre)
    {
        if (i < 0 || j < 0 || i == mat.size() || j == mat[0].size() || pre >= mat[i][j])
            return 0;
        if (dp[i][j])
            return dp[i][j];
        int l = dfs(mat, i, j - 1, mat[i][j]);
        int r = dfs(mat, i, j + 1, mat[i][j]);
        int u = dfs(mat, i - 1, j, mat[i][j]);
        int d = dfs(mat, i + 1, j, mat[i][j]);
        return dp[i][j] = max({l, r, u, d}) + 1;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int maxVal = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                maxVal = max(maxVal, dfs(matrix, i, j, -1));
        return maxVal;
    }
};