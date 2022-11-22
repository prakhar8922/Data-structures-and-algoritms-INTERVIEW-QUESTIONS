// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

// Constraints:

// 1 <= n <= 104

class Solution
{
public:
    int numSquares(int n)
    {

        vector<int> squares;
        for (int i = 1; i * i <= n; i++)
        {

            squares.push_back(i * i);
        }
        int sz = squares.size();
        int dp[sz + 1][n + 1];
        // vector<vector<int>>dp(sz+1,vector<int>(n+1,0));
        for (int i = 0; i <= sz; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 or j == 0)
                {
                    dp[i][j] = (j == 0) ? 0 : INT_MAX;
                }
            }
        }
        for (int i = 1; i <= sz; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (squares[i - 1] <= j)
                {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - squares[i - 1]]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[sz][n];
    }