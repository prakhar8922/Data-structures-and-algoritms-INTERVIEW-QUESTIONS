// Given a rod of length N inches and an array of prices, price[]. pricei denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Example 1:

// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by
// cutting in two pieces of lengths 2 and
// 6, i.e., 5+17=22.
// Example 2:

// Input:
// N=8
// Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
// Output: 24
// Explanation:
// The maximum obtainable value is
// 24 by cutting the rod into 8 pieces
// of length 1, i.e, 8*3=24.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function cutRod() which takes the array A[] and its size N as inputs and returns the maximum price obtainable.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 1000
// 1 ≤ Ai ≤ 105

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int cutRod(int price[], int n)
    {
        int w = n;
        int dp[n + 1][w + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        // i->current array size - n
        // j->current knapsack size - w
        int len[n];
        for (int i = 0; i < n; i++)
        {
            len[i] = i + 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (len[i - 1] <= j)
                {
                    dp[i][j] = max(price[i - 1] + dp[i][j - len[i - 1]], dp[i - 1][j]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][w];
    }
};