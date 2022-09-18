// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

// Example 1:

// Input: N = 4
// arr = {1, 5, 11, 5}
// Output: YES
// Explanation:
// The two parts are {1, 5, 5} and {11}.
// Example 2:

// Input: N = 3
// arr = {1, 3, 5}
// Output: NO
// Explanation: This array can never be
// partitioned into two such parts.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

// Expected Time Complexity: O(N*sum of elements)
// Expected Auxiliary Space: O(N*sum of elements)

// Constraints:
// 1 ≤ N ≤ 100
// 1 ≤ arr[i] ≤ 1000

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isSubsetSum(int arr[], int sum, int n)
    {
        bool dp[n + 1][sum + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }

    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        if (sum % 2 != 0)
            return 0;
        else
            return isSubsetSum(arr, sum / 2, n);
    }
};