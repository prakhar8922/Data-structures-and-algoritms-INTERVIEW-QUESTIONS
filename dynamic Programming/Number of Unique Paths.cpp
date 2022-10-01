// Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.

// Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

// Example 1:

// Input:
// A = 2, B = 2
// Output: 2
// Explanation: There are only two unique
// paths to reach the end of the matrix of
// size two from the starting cell of the
// matrix.
// Example 2:

// Input:
// A = 3, B = 4
// Output: 10
// Explanation: There are only 10 unique
// paths to reach the end of the matrix of
// size two from the starting cell of the
// matrix.
// Your Task:
// Complete NumberOfPath() function which takes 2 arguments(A and B) and returns the number of unique paths from top-left to the bottom-right cell.

// Expected Time Complexity: O(A*B).
// Expected Auxiliary Space: O(A*B).

// Constraints:
// 1 ≤ A ≤ 15
// 1 ≤ B ≤ 15

class Solution
{
public:
    // Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        int dp[a][b];
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[a - 1][b - 1];
    }
};