// Given an array arr of size N containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

// Example 1:

// Input: N = 4, arr[] = {1, 6, 11, 5}
// Output: 1
// Explanation:
// Subset1 = {1, 5, 6}, sum of Subset1 = 12
// Subset2 = {11}, sum of Subset2 = 11
// Example 2:
// Input: N = 2, arr[] = {1, 4}
// Output: 3
// Explanation:
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {4}, sum of Subset2 = 4

// Your Task:
// You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value

// Expected Time Complexity: O(N*|sum of array elements|)
// Expected Auxiliary Space: O(N*|sum of array elements|)

// Constraints:
// 1 ≤ N*|sum of array elements| ≤ 106

// The array contains non-negative integers.

#include <bits/stdc++.h>
using namespace std;

// // } Driver Code Ends
class Solution
{

public:
    int isSubset(int arr[], int n, int sum)
    {

        int dp[n + 1][sum + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int diff = INT_MAX;
        for (int i = 0; i <= sum / 2; i++)
        {
            if (dp[n][i] == true)
                diff = min(diff, sum - 2 * i);
        }
        return diff;
    }
    int minDifference(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int ans = isSubset(arr, n, sum);
        return ans;
    }
};