// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.

// Example 1:

// Input: str = "ababbbabbababa"
// Output: 3
// Explaination: After 3 partitioning substrings
// are "a", "babbbab", "b", "ababa".
// Example 2:

// Input: str = "aaabba"
// Output: 1
// Explaination: The substrings after 1
// partitioning are "aa" and "abba".

// Your Task:
// You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as the input parameter and returns the minimum number of partitions required.

// Expected Time Complexity: O(n*n) [n is the length of the string str]
// Expected Auxiliary Space: O(n*n)

// Constraints:
// 1 ≤ length of str ≤ 500

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int dp[501][501];
    bool ispalindrome(string str, int i, int j)
    {
        while (i < j)
        {
            if (str[i] != str[j])
                return false;

            i++, j--;
        }
        return true;
    }
    int solve(string str, int i, int j)
    {

        if (i >= j || ispalindrome(str, i, j))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int left = 0, right = 0;
            if (dp[i][k] != -1)
                left = dp[i][k];

            else
                left = solve(str, i, k);

            if (dp[k + 1][j] != -1)
                right = dp[k + 1][j];

            else
                right = solve(str, k + 1, j);

            int temp = left + right + 1;
            mn = min(temp, mn);
        }
        return dp[i][j] = mn;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        memset(dp, -1, sizeof(dp));
        return solve(str, 0, n - 1);
    }
};