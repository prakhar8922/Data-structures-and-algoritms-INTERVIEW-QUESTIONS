// Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].
// Note: Assume that you have an infinite supply of each type of coin.

// Example 1:

// Input:
// sum = 4 ,
// N = 3
// coins[] = {1,2,3}
// Output: 4
// Explanation: Four Possible ways are:
// {1,1,1,1},{1,1,2},{2,2},{1,3}.
// Example 2:

// Input:
// Sum = 10 ,
// N = 4
// coins[] ={2,5,3,6}
// Output: 5
// Explanation: Five Possible ways are:
// {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5}
// and {5,5}.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function count() which accepts an array coins[ ] its size N and sum as input parameters and returns the number of ways to make change for given sum of money.

// Expected Time Complexity: O(sum*N)
// Expected Auxiliary Space: O(sum)

// Constraints:
// 1 <= sum, N <= 103

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int count(int coins[], int n, int sum)
    {

        long long int dp[n + 1][sum + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};