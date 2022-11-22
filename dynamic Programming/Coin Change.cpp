

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104

class Solution
{
public:
    int dp[13][10001];
    int lowestCoin(vector<int> &coins, int amount, int n)
    {
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < amount + 1; j++)
            {
                if (i == 0 or j == 0)
                {
                    dp[i][j] = (j == 0) ? 0 : INT_MAX - 1; // if j=0 dp[i][j]=0 else int max
                }
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j]; // if the value of coin is > than amount ignore it
                }
                else
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
        return dp[n][amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int ans = lowestCoin(coins, amount, coins.size());
        return (ans == INT_MAX - 1) ? -1 : ans;
    }
};

// int dp[12 + 1][10000 + 1];

//     int findLowestCoins(vector<int> &coins, int arraySize, int amount) {
//         for (int i = 0; i < arraySize + 1; i++)
//             for (int j = 0; j < amount + 1; j++)
//                 if (i == 0 || j == 0)
//                     dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;

//         for (int i = 1; i < arraySize + 1; i++) {
//             for (int j = 1; j < amount + 1; j++) {
//                 if (coins[i - 1] > j)
//                     dp[i][j] = 0 + dp[i - 1][j];
//                 else
//                     dp[i][j] = min(0 + dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
//             }
//         }

//         return dp[arraySize][amount];
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int res = findLowestCoins(coins, coins.size(), amount);
//         return (res == INT_MAX - 1) ? -1 : res;