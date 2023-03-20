// 139. Word Break
// Medium
// 13.6K
// 575
// Companies
// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.

class Solution
{
private:
    bool wordBreak(string s, unordered_set<string> &set, vector<int> &memo, int start)
    {
        if (start == s.size())
        {
            return true;
        }
        if (memo[start] != -1)
        {
            return memo[start];
        }
        for (int i = start; i < s.size(); i++)
        {
            if (set.count(s.substr(start, i + 1 - start)) && wordBreak(s, set, memo, i + 1))
            {
                memo[start] = true;
                return true;
            }
        }
        return memo[start] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> memo(s.size(), -1);
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wordBreak(s, set, memo, 0);
    }
};