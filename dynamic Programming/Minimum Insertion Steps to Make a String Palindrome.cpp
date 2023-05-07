// 1312. Minimum Insertion Steps to Make a String Palindrome
// Hard
// 4K
// 56
// Companies
// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.
// Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".
// Example 3:

// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.
// Accepted
// 117.6K
// Submissions
// 170.3K
// Acceptance Rate
// 69.0%

class Solution
{
public:
    int lcs(string s1, string s2, int m, int n)
    {
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 or j == 0)
                    dp[i][j] = 0;
                else
                {
                    if (s1[i - 1] == s2[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    int minInsertions(string s)
    {
        // The idea is to find the LCS between the original string s and its reverse string s'. The length of LCS will give us the number of characters that are already palindrome in s. We can subtract this length from the length of s to get the number of characters we need to add to make s palindrome.
        int m = s.size();
        string str = s;
        reverse(str.begin(), str.end());
        return s.size() - lcs(s, str, m, m);
    }
};