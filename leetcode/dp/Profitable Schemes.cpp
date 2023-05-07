// 879. Profitable Schemes
// Hard
// 1.6K
// 111
// Companies
// There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

// Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

// Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.

// Example 1:

// Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
// Output: 2
// Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
// In total, there are 2 schemes.
// Example 2:

// Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
// Output: 7
// Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
// There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).

// Constraints:

// 1 <= n <= 100
// 0 <= minProfit <= 100
// 1 <= group.length <= 100
// 1 <= group[i] <= 100
// profit.length == group.length
// 0 <= profit[i] <= 100
// Accepted
// 55.5K
// Submissions
// 111.9K
// Acceptance Rate
// 49.6%

class Solution
{
public:
    int mod = 1e9 + 7;
    int func(int idx, int n, int mP, vector<int> &group, vector<int> &profit, vector<vector<vector<int>>> &dp)
    {
        // Base case: If we have taken more people than we were allowed, we cannot make a profitable scheme.
        if (n < 0)
            return 0;

        // Base case: If we have exhausted the list of crimes, we cannot make any more profit.
        if (idx == group.size())
        {
            if (mP > 0)
                return 0; // If we still have some minimum profit left to make, we cannot achieve our goal.
            else
                return 1; // If we have achieved our minimum profit or more, we have made a profitable scheme.
        }
        // This indicates that the minimum profit required has been achieved, and there is no profit left to be made. Therefore, all subsequent recursive calls with minProfit <= 0 will belong to the same class where minProfit is equal to 0.
        if (mP < 0)
            mP = 0;

        if (dp[idx][n][mP] != -1)
            return dp[idx][n][mP];

        int count = 0;
        count += func(idx + 1, n - group[idx], mP - profit[idx], group, profit, dp) % mod; // If we select the current crime, update the number of people and profit required.
        count += func(idx + 1, n, mP, group, profit, dp) % mod;                            // If we don't select the current crime, do not update the number of people and profit required.

        return dp[idx][n][mP] = count % mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int sz = group.size();
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return func(0, n, minProfit, group, profit, dp);
    }
};