// 2218. Maximum Value of K Coins From Piles
// Hard
// 1.3K
// 17
// Companies
// There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

// In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

// Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.

// Example 1:

// Input: piles = [[1,100,3],[7,8,9]], k = 2
// Output: 101
// Explanation:
// The above diagram shows the different ways we can choose k coins.
// The maximum total we can obtain is 101.
// Example 2:

// Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
// Output: 706
// Explanation:
// The maximum total can be obtained if we choose all coins from the last pile.

// Constraints:

// n == piles.length
// 1 <= n <= 1000
// 1 <= piles[i][j] <= 105
// 1 <= k <= sum(piles[i].length) <= 2000
// Accepted
// 28.2K
// Submissions
// 50.2K
// Acceptance Rate
// 56.2%

class Solution
{
public:
    int func(int idx, int k, vector<vector<int>> &piles, vector<vector<int>> &dp)
    {
        if (dp[idx][k] != -1)
            return dp[idx][k];
        if (idx == piles.size() or k == 0)
            return 0;
        int ans = func(idx + 1, k, piles, dp); // we do not pick any coin from the current pile
        int curr = 0;
        // This loop considers picking each coin from the current pile and adds the value of each picked coin to the curr variable. It then calculates the maximum value that can be obtained by picking k-j-1 coins from the remaining piles and adds it to curr. The overall maximum value is stored in the ans variable.
        for (int j = 0; j < piles[idx].size() and j < k; j++)
        {
            curr += piles[idx][j];
            ans = max(ans, func(idx + 1, k - j - 1, piles, dp) + curr); // taking each coin from the curr piles and using it calculate the max with other piles
        }
        return dp[idx][k] = ans;
    }
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return func(0, k, piles, dp);
    }
};