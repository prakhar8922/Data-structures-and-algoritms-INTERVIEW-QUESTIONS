// 1444. Number of Ways of Cutting a Pizza
// Hard
// 1.6K
// 90
// Companies
// Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts.

// For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

// Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.

// Example 1:

// Input: pizza = ["A..","AAA","..."], k = 3
// Output: 3
// Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
// Example 2:

// Input: pizza = ["A..","AA.","..."], k = 3
// Output: 1
// Example 3:

// Input: pizza = ["A..","A..","..."], k = 1
// Output: 1

// Constraints:

// 1 <= rows, cols <= 50
// rows == pizza.length
// cols == pizza[i].length
// 1 <= k <= 10
// pizza consists of characters 'A' and '.' only.
// Accepted
// 60.3K
// Submissions
// 94.1K
// Acceptance Rate
// 64.1%

class Solution
{
public:
    long long mod = 1e9 + 7;

    // This function checks whether a given subrectangle of the pizza contains an apple ('A')
    bool isValid(vector<string> &pizza, int rowStart, int colStart, int rowEnd, int colEnd)
    {
        for (int i = rowStart; i <= rowEnd; i++)
        {
            for (int j = colStart; j <= colEnd; j++)
            {
                if (pizza[i][j] == 'A')
                    return true;
            }
        }
        return false;
    }

    // This function recursively computes the number of ways to cut the pizza with 'cutsleft' cuts
    // starting from the cell (rowStart, colStart)
    int solve(vector<string> &pizza, int rowStart, int colStart, int cutsleft, vector<vector<vector<int>>> &dp)
    {
        int ans = 0;
        int m = pizza.size(), n = pizza[0].size();

        // Base case: no more cuts left to make
        if (cutsleft == 0)
            return 1;

        // If this subproblem has already been solved, return the precomputed result
        if (dp[rowStart][colStart][cutsleft] != -1)
            return dp[rowStart][colStart][cutsleft];

        // Try making a horizontal cut between 'rowStart' and 'row' and recursively solve the subproblems
        for (int row = rowStart; row < m - 1; row++)
        {
            bool upperhalfvalid = isValid(pizza, rowStart, colStart, row, n - 1);
            bool lowerhalfvalid = isValid(pizza, row + 1, colStart, m - 1, n - 1);
            if (upperhalfvalid and lowerhalfvalid)
            {
                int nextways = solve(pizza, row + 1, colStart, cutsleft - 1, dp);
                ans = (ans + nextways) % mod;
            }
        }

        // Try making a vertical cut between 'colStart' and 'col' and recursively solve the subproblems
        for (int col = colStart; col < n - 1; col++)
        {
            bool lefthalfvalid = isValid(pizza, rowStart, colStart, m - 1, col);
            bool righthalfvalid = isValid(pizza, rowStart, col + 1, m - 1, n - 1);
            if (lefthalfvalid and righthalfvalid)
            {
                int nextways = solve(pizza, rowStart, col + 1, cutsleft - 1, dp);
                ans = (ans + nextways) % mod;
            }
        }

        // Cache the result of this subproblem
        return dp[rowStart][colStart][cutsleft] = ans;
    }

    // This function computes the number of ways to cut the pizza into at most 'k' pieces
    int ways(vector<string> &pizza, int k)
    {
        int m = pizza.size(), n = pizza[0].size();

        // Special case: only one cut left to make
        if (k == 1)
            return (isValid(pizza, 0, 0, m - 1, n - 1) ? 1 : 0);

        // Initialize the memoization table with -1
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));

        // Call the recursive function to solve the problem
        int ans = solve(pizza, 0, 0, k - 1, dp);

        return ans;
    }
};