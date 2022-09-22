// Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
// For Example:
// ab: Number of insertions required is 1. bab or aba
// aa: Number of insertions required is 0. aa
// abcd: Number of insertions required is 3. dcbabcd

// Example 1:

// Input: str = "abcd"
// Output: 3
// Explanation: Inserted character marked
// with bold characters in dcbabcd
// Example 2:

// Input: str = "aa"
// Output: 0
// Explanation:"aa" is already a palindrome.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countMin() which takes the string str as inputs and returns the answer.

// Expected Time Complexity: O(N2), N = |str|
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 ≤ |str| ≤ 103
// str contains only lower case alphabets.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int lcs(string s1, string s2, int n, int m)
    {
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (s1[i - 1] == s2[j - 1])
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
    int countMin(string str)
    {
        string s = str;
        reverse(s.begin(), s.end());
        int n = str.size();
        int lcsSize = lcs(str, s, n, n);
        return (n - lcsSize);
    }
};