// Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

// Example 1:

// Input:
// A = 6, B = 6
// str1 = ABCDGH
// str2 = AEDFHR
// Output: 3
// Explanation: LCS for input Sequences
// “ABCDGH” and “AEDFHR” is “ADH” of
// length 3.
// Example 2:

// Input:
// A = 3, B = 2
// str1 = ABC
// str2 = AC
// Output: 2
// Explanation: LCS of "ABC" and "AC" is
// "AC" of length 2.
// Your Task:
// Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

// Expected Time Complexity : O(|str1|*|str2|)
// Expected Auxiliary Space: O(|str1|*|str2|)

// Constraints:
// 1<=size(str1),size(str2)<=103

// Top-down(Memozisation approach)
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence
int static dp[1001][1001];
// class Solution
// {
// public:
//     // Function to find the length of longest common subsequence in two strings.
//     int lc(int x, int y, string s1, string s2)
//     {
//         if (x == 0 || y == 0)
//         {
//             return 0;
//         }
//         if (dp[x][y] != -1)
//         {
//             return dp[x][y];
//         }
//         if (s1[x - 1] == s2[y - 1])
//         {
//             return dp[x][y] = 1 + lc(x - 1, y - 1, s1, s2);
//         }
//         else
//         {
//             return dp[x][y] = max(lc(x - 1, y, s1, s2), lc(x, y - 1, s1, s2));
//         }
//     }
//     int lcs(int x, int y, string s1, string s2)
//     {
//         memset(dp, -1, sizeof(dp));
//         return lc(x, y, s1, s2);
//     }
// };
// Bottom down approach
class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.

    int lcs(int x, int y, string s1, string s2)
    {
        for (int i = 0; i <= x; i++)
        {
            for (int j = 0; j <= y; j++)
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
        return dp[x][y];
    }
};
