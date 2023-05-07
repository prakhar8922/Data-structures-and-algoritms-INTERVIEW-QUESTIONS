// 1639. Number of Ways to Form a Target String Given a Dictionary
// Hard
// 782
// 42
// Companies
// You are given a list of strings of the same length words and a string target.

// Your task is to form target using the given words under the following rules:

// target should be formed from left to right.
// To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
// Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
// Repeat the process until you form the string target.
// Notice that you can use multiple characters from the same string in words provided the conditions above are met.

// Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

// Example 1:

// Input: words = ["acca","bbbb","caca"], target = "aba"
// Output: 6
// Explanation: There are 6 ways to form target.
// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
// Example 2:

// Input: words = ["abba","baab"], target = "bab"
// Output: 4
// Explanation: There are 4 ways to form target.
// "bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
// "bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
// "bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
// "bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 1000
// All strings in words have the same length.
// 1 <= target.length <= 1000
// words[i] and target contain only lowercase English letters.
// Accepted
// 22.2K
// Submissions
// 44K
// Acceptance Rate
// 50.3%

class Solution
{
public:
    int mod = 1e9 + 7;
    int func(int idx, int j, vector<string> &words, string &target, vector<vector<int>> &dp)
    {
        // Base case: target has been fully matched
        if (j == target.size())
        {
            return 1;
        }
        // Base case: current word has been fully considered or remaining length of word is less than remaining length of target
        if (idx == words[0].size() || words[0].size() - idx < target.size() - j)
        {
            return 0;
        }
        if (dp[idx][j] != -1)
        {
            return dp[idx][j];
        }
        long long ans = 0;
        // Recursively call function without matching any character in current word
        ans += (func(idx + 1, j, words, target, dp)) % mod;
        for (int i = 0; i < words.size(); i++)
        {
            // If current character of word matches current character of target
            if (words[i][idx] == target[j])
            {
                // Recursively call function while matching current character of word and target
                ans += (func(idx + 1, j + 1, words, target, dp)) % mod;
            }
        }
        return dp[idx][j] = ans % mod;
    }

    int numWays(vector<string> &words, string target)
    {
        vector<vector<int>> dp(words[0].size(), vector<int>(target.size(), -1));
        return func(0, 0, words, target, dp);
    }
};