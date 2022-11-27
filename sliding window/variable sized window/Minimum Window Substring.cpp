// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int i = 0, j = 0, start = 0;
        unordered_map<char, int> mp;
        for (auto it : t)
        {
            mp[it]++;
        }
        int ansL = INT_MAX;
        int count = mp.size();
        while (j < s.size())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;
            if (count == 0)
            {
                while (count == 0)
                { // keep on increasing i index to reduce the length of the substring
                    if (j - i + 1 < ansL)
                    {
                        ansL = j - i + 1;
                        start = i;
                    }
                    mp[s[i]]++; // if similar character is encountered again
                    if (mp[s[i]] == 1)
                        count++;

                    i++;
                }
            }
            j++;
        }
        return ansL == INT_MAX ? "" : s.substr(start, ansL);
    }
};