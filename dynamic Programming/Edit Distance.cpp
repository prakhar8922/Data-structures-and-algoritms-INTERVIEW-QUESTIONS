// Given two strings s and t. Return the minimum number of operations required to convert s to t.
// The possible operations are permitted:

// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.

// Example 1:

// Input:
// s = "geek", t = "gesek"
// Output: 1
// Explanation: One operation is required
// inserting 's' between two 'e's of str1.
// Example 2:

// Input :
// s = "gfg", t = "gfg"
// Output:
// 0
// Explanation: Both strings are same.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function editDistance() which takes strings s and t as input parameters and returns the minimum number of operation to convert the string s to string t.

// Expected Time Complexity: O(|s|*|t|)
// Expected Space Complexity: O(|s|*|t|)

// Constraints:

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int editDistance(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        int dp[m + 1][n + 1];

        // If first string is empty, the only option is to
        // insert all characters of second string into first
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }
        // If second string is empty, the only option is to
        // remove all characters of first string
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // dp[i - 1][j - 1]) Replace
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n];
    }
};